#include "../includes/minishell.h"

void	redir_append(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
		perror("fd");
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void	redir_output(char *file)
{
	int fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		perror("fd");
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void	redir_input(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		perror("fd");
	dup2(fd, STDIN_FILENO);
	close(fd);
}
