/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatela <kchatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:19:27 by pdangwal          #+#    #+#             */
/*   Updated: 2025/11/06 17:03:58 by kchatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    deallocate_tree(t_tree **root)
{
    int i;

    if (!*root)
        return ;
    i = 0;
    deallocate_tree(&(*root)->left);
    deallocate_tree(&(*root)->right);
    while((*root)->argv[i])
    {
        free((*root)->argv[i]);
        i++;
    }
    free((*root)->argv);
    free((*root)->token);
    free(*root);
}

void    cleanup(char **line, t_token **tokens, t_shell *shell, t_tree **root)
{
    t_token *tmp;
    t_env *tmpshell;
    if (*line)
        free(*line);
    if (*tokens)
    {
        while(*tokens)
        {
            if ((*tokens)->token)
                free((*tokens)->token);
            tmp = (*tokens)->next;
            free(*tokens);
            *tokens = tmp;
        }
    }
    if (shell)
    {
        while(shell->env_list)
        {
            free(shell->env_list->key);
            free(shell->env_list->value);
            tmpshell = shell->env_list->next;
            free(shell->env_list);
            shell->env_list = tmpshell;
        }
        free(shell);
    }
    deallocate_tree(root);
}

int main(int argc, char **argv, char **envp)
{
    (void)argc;
    (void)argv;
	(void)envp;

    t_shell shell;
    char *line;
	t_token *tokens;
	t_tree *root;

    shell_init(&shell, envp);

    while (1)
    {
        line = readline("minishell% ");
        if(!line)
        {
            //cleanup(&line, &tokens, &shell, &root);
            exit(shell.exit_status);
            break ;
        }
        if (line[0] != '\0')
            add_history(line);
        
        if (g_signal_status == 1)
		{
			shell.exit_status = 130;
			g_signal_status = 0;
		}

		tokens = lexer(line);
        tokens = expander(tokens, &shell);
		root = parse_e(&tokens);
        
		//print_tree(root, 0);
        exec_tree(root, &shell);
        
        //cleanup(&line, &tokens, NULL, &root);
    }
    //rl_clear_history();
    return (0);
}
