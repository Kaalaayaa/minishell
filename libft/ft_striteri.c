/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatela <kchatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:07:56 by kchatela          #+#    #+#             */
/*   Updated: 2024/11/29 14:46:58 by kchatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/*#include <stdio.h>

void	print_char(unsigned int index, char *c)
{
	printf("Index %u: %c\n", index, *c);
}

int main()
{
	char str[] = "Hello, world!";
	
	ft_striteri(str, print_char);

	return 0;
}*/