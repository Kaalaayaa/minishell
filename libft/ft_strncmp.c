/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatela <kchatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:51:42 by kchatela          #+#    #+#             */
/*   Updated: 2024/11/25 14:52:26 by kchatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char) s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	if (i < n)
	{
		return ((unsigned char) s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	int		n;
	char	string1[50];
	char	string2[50];

	n = 9;
	strcpy(string1, "1234567890");
	strcpy(string2, "1234567");

	printf(" \n");
	printf("== TEST ==\nS1: %s\nS2: %s\nn:%d\n", string1, string2, n);
	printf("Result strcmp(): %d\n", strncmp(string1, string2, n));
	printf("Result 'my' ft_strcmp(): %d\n", ft_strncmp(string1, string2, n));

	return (0);
}*/
