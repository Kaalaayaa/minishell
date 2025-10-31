#include "minishell.h"

static char *join_first(char *res, char *s1, int *i)
{
    while (s1[*i])
    {
        res[*i] = s1[*i];
        (*i)++;
    }
    return (res);
}

static char *join_rest(char *res, char *str, int *pos)
{
    int j;

    j = 0;
    while (str[j])
        res[(*pos)++] = str[j++];
    return (res);
}

char *ft_strjoin_three(char *s1, char *s2, char *s3)
{
    int len;
    int i;
    char *res;

    if (!s1 || !s2 || !s3)
        return (NULL);
    len = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
    res = malloc(sizeof(char) * (len + 1));
    if (!res)
        return (NULL);
    i = 0;
    res = join_first(res, s1, &i);
    res = join_rest(res, s2, &i);
    res = join_rest(res, s3, &i);
    res[i] = '\0';
    return (res);
}

static void swap_strings(char **s1, char **s2)
{
    char *tmp;

    tmp = *s1;
    *s1 = *s2;
    *s2 = tmp;
}

void ft_sort_str_tab(char **tab)
{
    int i;
    int j;

    if (!tab)
        return;
    i = 0;
    while (tab[i])
    {
        j = i + 1;
        while (tab[j])
        {
            if (ft_strcmp(tab[i], tab[j]) > 0)
                swap_strings(&tab[i], &tab[j]);
            j++;
        }
        i++;
    }
}

int env_size(t_env *env)
{
    int i;

    i = 0;
    while (env)
    {
        i++;
        env = env->next;
    }
    return (i);
}

char *env_to_str(t_env *env)
{
    char *str;

    if (!env || !env->key)
        return (NULL);
    if (env->value)
    {
        str = ft_strjoin_three(env->key, "=", env->value);
        if (!str)
            return (NULL);
        return (str);
    }
    str = ft_strdup(env->key);
    if (!str)
        return (NULL);
    return (str);
}