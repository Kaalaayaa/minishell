/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatela <kchatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 19:28:32 by pdangwal          #+#    #+#             */
/*   Updated: 2025/12/05 20:11:02 by kchatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	write_lines_child(char *argv, int fd[2])
{
	close(fd[0]);
	close_fd_in_range(2, fd[1]);
	close_fd_in_range(fd[1], 1024);
	write(fd[1], argv, ft_strlen(argv));
	write(fd[1], "\n", 1);
	close(fd[1]);
	exit(0);
}

static int	write_lines_parent(pid_t pid, int fd[2])
{
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	waitpid(pid, NULL, 0);
	return (1);
}

static int	write_lines_fork(char *argv, int fd[2])
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		close(fd[0]);
		close(fd[1]);
		return (0);
	}
	if (pid == 0)
		write_lines_child(argv, fd);
	return (write_lines_parent(pid, fd));
}

int	write_lines(char *argv)
{
	int		fd[2];

	if (!argv || pipe(fd) == -1)
		return (0);
	return (write_lines_fork(argv, fd));
}

void	update_exit_status(int status, t_shell *shell)
{
	if (WIFEXITED(status))
		shell->exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		shell->exit_status = 128 + WTERMSIG(status);
}
