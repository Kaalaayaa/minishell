/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatela <kchatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:23:35 by pdangwal          #+#    #+#             */
/*   Updated: 2025/11/12 15:34:04 by kchatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	pipe_init_and_left_fork(t_tree *tree, t_shell *shell, int fd[2], pid_t *left_pid)
{
	if (!tree || !shell || pipe(fd) == -1)
		return (1);
	shell->in_pipe = true;
	*left_pid = fork();
	if (*left_pid == -1)
	{
		close(fd[0]);
		close(fd[1]);
		return (1);
	}
	if (*left_pid == 0)
		pipe_end(fd, 0, tree, shell);
	return (0);
}

static int	pipe_right_fork(t_shell *shell, int fd[2], pid_t left_pid, pid_t *right_pid)
{
	*right_pid = fork();
	if (*right_pid == -1)
	{
		close(fd[0]);
		close(fd[1]);
		waitpid(left_pid, NULL, 0);
		return (1);
	}
	if (*right_pid == 0)
		pipe_end(fd, 1, shell->tree, shell);
	return (0);
}

static void	pipe_cleanup_and_status(t_shell *shell, 
	int fd[2], pid_t left_pid, pid_t right_pid)
{
	int	status;

	close(fd[0]);
	close(fd[1]);
	waitpid(left_pid, NULL, 0);
	waitpid(right_pid, &status, 0);
	shell->in_pipe = false;
	handle_pipe_status(status, shell);
}

void	exec_pipe(t_tree *tree, t_shell *shell)
{
	int		fd[2];
	pid_t	left_pid;
	pid_t	right_pid;

	if (pipe_init_and_left_fork(tree, shell, fd, &left_pid))
		return ;
	if (pipe_right_fork(shell, fd, left_pid, &right_pid))
		return ;
	pipe_cleanup_and_status(shell, fd, left_pid, right_pid);
}

void	execute_foreign(char **envp, char *path, t_tree *tree)
{
	char	*execpath;

	verify_path(envp, path, tree);
	execpath = path;
	if (ft_strchr(tree->argv[0], '/'))
		execpath = tree->argv[0];
	execve(execpath, tree->argv, envp);
	free_exec_resources(envp, path);
	if (errno == EACCES)
		print_and_exit("minishell: ", tree->argv[0], ": Permission denied\n",
			126);
	else if (errno == ENOENT)
		print_and_exit("minishell: ", tree->argv[0],
			": No such file or directory\n", 127);
	print_error("minishell: ", tree->argv[0], ": ");
	print_error(strerror(errno), "\n", NULL);
	exit(127);
}

static int	exec_cmd_prechecks(t_tree *tree, t_shell *shell)
{
	if (!tree || !tree->argv || !tree->argv[0])
		return (1);
	if (handle_var_assignment(tree, shell))
		return (1);
	if (run_parent_builtin(tree, shell))
		return (1);
	return (0);
}

static int	exec_cmd_setup(t_tree *tree, t_shell *shell, char ***envp, char **path)
{
	*envp = get_envp(shell->env_list);
	*path = get_path(tree->argv[0], shell);
	if (check_path_unset(tree, shell, *envp, *path))
	{
		free_exec_resources(*envp, *path);
		return (1);
	}
	if (!shell->in_pipe)
		setup_signals_parent();
	return (0);
}

static void	exec_cmd_fork_exec(t_tree *tree, t_shell *shell, char **envp, char *path)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
	{
		free_exec_resources(envp, path);
		return ;
	}
	if (pid == 0)
		child_exec(tree, shell, envp, path);
	waitpid(pid, &status, 0);
	if (!shell->in_pipe)
		setup_signals_prompt();
	free_exec_resources(envp, path);
	handle_cmd_signal(status, shell);
}

void	exec_cmd(t_tree *tree, t_shell *shell)
{
	char	**envp;
	char	*path;

	if (exec_cmd_prechecks(tree, shell))
		return ;
	if (exec_cmd_setup(tree, shell, &envp, &path))
		return ;
	exec_cmd_fork_exec(tree, shell, envp, path);
}

void	exec_with_redir(t_tree *tree, t_shell *shell)
{
	int		outfd;
	int		infd;
	int		res;
	t_redir	*redir;

	redir = tree->redirections;
	res = 1;
	outfd = dup(STDOUT_FILENO);
	infd = dup(STDIN_FILENO);
	while (redir && redir->filename && redir->type)
	{
		if (!redir_allocation(redir, shell))
		{
			res = 0;
			shell->exit_status = 1;
			break ;
		}
		redir = redir->next;
	}
	if (res)
		exec_cmd(tree, shell);
	dup2(outfd, STDOUT_FILENO);
	dup2(infd, STDIN_FILENO);
	close(outfd);
	close(infd);
}

void	exec_tree(t_tree *tree, t_shell *shell)
{
	if (!tree)
		return ;
	if (tree->type == PIPE)
	{
		exec_pipe(tree, shell);
		return ;
	}
	else if (tree->type == WORD)
	{
		exec_with_redir(tree, shell);
		return ;
	}
}
