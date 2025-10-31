#include "minishell.h"

int ft_strcmp(const char *s1, const char *s2)
{
    size_t i = 0;
    if (!s1 || !s2)
        return (s1 - s2);
    while (s1[i] && s2[i])
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (s1[i] - s2[i]);
}

int	is_valid_identifier(char *key)
{
	int	i;

	if (!key || (!ft_isalpha(key[0]) && key[0] != '_'))
		return (0);
	i = 1;
	while (key[i])
	{
		if (!ft_isalnum(key[i]) && key[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

void	add_or_update_env(t_env **env, char *key, char *value)
{
	t_env	*node;

	if (!env || !key)
		return;

	node = *env;
	while (node)
	{
		if (ft_strcmp(node->key, key) == 0)
		{
			free(node->value);
			if (value != NULL)
				node->value = ft_strdup(value);
			else
				node->value = NULL;
			return;
		}
		node = node->next;
	}

	node = malloc(sizeof(t_env));
	if (!node)
		return;

	node->key = ft_strdup(key);
	if (value)
		node->value = ft_strdup(value);
	else
		node->value = NULL;

	node->next = *env;
	*env = node;
}