/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatela <kchatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:34:21 by kchatela          #+#    #+#             */
/*   Updated: 2024/11/25 14:43:49 by kchatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*str;
	unsigned char		char_c;
	size_t				i;

	str = (unsigned char *) s;
	char_c = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (str[i] == char_c)
		{
			return ((void *) &str[i]);
		}
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char str[] = "Hello, World!";
// 	char to_find = 'o';
// 	char *result;

// 	result = ft_memchr(str, to_find, sizeof(str));
// 	printf("String: '%s'\n", str);
// 	printf("Byte to be located: '%c'\n", to_find);

// 	if (result == NULL)
// 		printf("Character not found\n\n");
// 	else
// 		printf("Character found at position %ld\n\n", result - str);

// 	to_find = '\0';
// 	result = ft_memchr(str, to_find, sizeof(str));
// 	printf("String: '%s'\n", str);
// 	printf("Byte to be located: '%c'\n", to_find);
// 	if (result == NULL)
// 		printf("Character not found\n\n");
// 	else
// 		printf("Character found at position %ld\n\n", result - str);

// 	to_find = 'x';
// 	result = ft_memchr(str, to_find, sizeof(str));
// 	printf("String: '%s'\n", str);
// 	printf("Byte to be located: '%c'\n", to_find);
// 	if (result == NULL)
// 		printf("Character not found\n\n");
// 	else
// 		printf("Character found at position %ld\n\n", result - str);

// 	return (0);
// }
