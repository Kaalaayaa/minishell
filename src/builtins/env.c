#include "minishell.h"

int	builtin_env(t_shell *shell)
{
	t_env	*tmp;

	tmp = shell->env_list;
    //prints list of env
	while (tmp != NULL)
	{
		if (tmp->value != NULL)
			printf("%s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
	return (0);
}
