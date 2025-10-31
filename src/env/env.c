#include "minishell.h"

t_env *create_node_env(char *str)
{
    t_env *node = malloc(sizeof(t_env));
    if(!node)
        return NULL;
    
    char *equal_sign = strchr(str, '=');
    if(equal_sign)
    {
        node->key = strndup(str, equal_sign - str); //extract key before =
        node->value = strdup(equal_sign + 1); // extract value after =
    }
    else
    {
        node->key = strdup(str);
        node->value = NULL;
    }
    node->next = NULL;
    return node;
}

t_env *env_list_init(char **envp)
{
    t_env *head = NULL;
    t_env *tail = NULL;

    int i = 0;

    while(envp[i])
    {
        t_env *new_node = create_node_env(envp[i]);
        if(!new_node)
            return head;
        if(!head)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
        i++;
    }
    return head;
}