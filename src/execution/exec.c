#include "../includes/minishell.h"


void	exec_pipe(t_tree *tree, t_shell *shell)
{
	int	fd[2];
	pid_t	left_pid;
	pid_t	right_pid;

	if (!tree || !shell)
		return ;
	if (pipe(fd) == -1)
		return ;
	left_pid = fork();
	if (left_pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		exec_tree(tree->left, shell);
		exit(0);
	}
	right_pid = fork();
	if (right_pid == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		exec_tree(tree->right, shell);
		exit(0);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(left_pid, NULL, 0);
	waitpid(right_pid, NULL, 0);
}

char	*get_path_env(t_shell *shell)
{
	t_env *env;

	env = shell->env_list;
	while(env->key)
	{
		if (ft_strncmp(env->key, "PATH", 4) == 0)
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

char	*full_path(char *argv)
{
	if (!argv)
		return (NULL);
	if (access(argv, X_OK) == 0)
	{
		return (ft_strdup(argv));
	}
	return (NULL);
}

char	**check_path(char *argv, t_shell *shell)
{
	char *path_env;
	char **paths;

	if (!argv)
		return (NULL);
	
	path_env = get_path_env(shell);
	
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');

	return (paths);
}

char	*get_path(char *argv, t_shell *shell)
{
	char	*tmp;
	char	**paths;
	char 	*fullpath;
	int		i;

	if (ft_strchr(argv, '/'))
		return (full_path(argv));
	
	paths = check_path(argv, shell);
	
	if (!paths)
		return (NULL);
	i = 0;
	while(paths[i])
	{
		ft_trim_end(paths[i], ':');
		tmp = ft_strjoin(paths[i], "/");
		
		fullpath = ft_strjoin(tmp, argv);
		free(tmp);
		if (access(fullpath, X_OK) == 0)
		{
			//might have to free the split here;
			return (fullpath);
		}
		free(fullpath);
		i++;
	}
	//ft_freesplit() here too;
	return (NULL);
	
}
void	exec_cmd(t_tree *tree, t_shell *shell)
{
	pid_t	pid;
	char	*path;

	if (!tree)
		return ;
	
	if (is_builtin(tree->argv[0]))
		execute_builtin(tree->argv, shell);
	else
	{
		pid = fork();
		if (pid == 0) // child process
		{
			path = get_path(tree->argv[0], shell);
			
			
			if (!path)
			{
				perror("command not foudn");
				exit(127);
			}
			execve(path, tree->argv, NULL); // the null here needs to be char**envp
		}
		else
			waitpid(pid, NULL, 0);
	}
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
		exec_cmd(tree, shell);
		return ;
	}
}
