/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigaction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatela <kchatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:34:06 by pdangwal          #+#    #+#             */
/*   Updated: 2025/10/31 17:09:43 by kchatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
int	main(int argc, char *argv[])
{
	struct sigaction sa;

	sa.sa_handler = &handle_sigtstp;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGTSTP, &sa, NULL);
	while(1)
	{
		printf("stop me\n");
		sleep(1);
	}

}
//*/
