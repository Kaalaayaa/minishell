
#include "../includes/minishell.h"

void	free_split(char **argv)
{
	int	i;

	if (!argv || !argv[0])
		return ;
	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	free_redirections(t_redir **list)
{
	t_redir	*tmp;

	if (!list || !*list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->filename);
		free(*list);
		*list = tmp;
	}
}

void	deallocate_tree(t_tree **root)
{
	int	i;

	if (!root || !*root)
		return ;
	i = 0;
	deallocate_tree(&(*root)->left);
	deallocate_tree(&(*root)->right);
	if ((*root)->redirections)
		free_redirections(&(*root)->redirections);
	if ((*root)->argv && (*root)->argv[0])
	{
		while ((*root)->argv[i])
		{
			free((*root)->argv[i]);
			i++;
		}
		free((*root)->argv);
	}
	free((*root)->token);
	free(*root);
}

void	free_tokens(t_token **tokens)
{
	t_token	*tmp;

	if (!tokens || !*tokens)
		return ;
	while (*tokens)
	{
		free((*tokens)->token);
		tmp = (*tokens)->next;
		free(*tokens);
		*tokens = tmp;
	}
}

void	free_shell(t_shell *shell)
{
	t_env	*tmpshell;

	if (!shell)
		return ;
	while (shell->env_list)
	{
		free(shell->env_list->key);
		free(shell->env_list->value);
		tmpshell = shell->env_list->next;
		free(shell->env_list);
		shell->env_list = tmpshell;
	}
	// free(shell);
}

void	cleanup(t_token **tokens, t_shell *shell, t_tree **root)
{
	free_tokens(tokens);
	free_shell(shell);
	deallocate_tree(root);
}