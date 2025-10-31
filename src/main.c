/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatela <kchatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:19:27 by pdangwal          #+#    #+#             */
/*   Updated: 2025/10/31 17:48:22 by kchatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
    (void)argc;
    (void)argv;
	(void)envp;

    t_shell shell;
    char *line;
	t_token *tokens;
	t_tree *root;

    shell.env_list = env_list_init(envp);
	shell.exit_status = 0;

    while (1)
    {
        line = readline("minishell% ");
        if (line[0] != '\0')
            add_history(line);

		tokens = lexer(line);
		root = parse_e(&tokens);
		print_tree(root, 0);
		
		//execute_ast(root, &shell);
		
        if(is_builtin(root->argv[0]))
            execute_builtin(root->argv, &shell);
        else
            //execute_external(root->argv, &shell);
			
        free(line);
    }
    return (0);
}