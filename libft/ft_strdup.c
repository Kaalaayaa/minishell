/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatela <kchatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:50:52 by kchatela          #+#    #+#             */
/*   Updated: 2024/11/26 10:50:45 by kchatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dest;

	dest = malloc(ft_strlen(str) + 1 * sizeof(char));
	if (!dest)
	{
		return (NULL);
	}
	ft_strlcpy(dest, str, ft_strlen(str)+ 1);
	return (dest);
}

// #include <stdio.h>

// int main(void)
// {
//      // Test 1: Regular string
//     char str1[] = "Kalaya";
//     char *dup1 = ft_strdup(str1);
//     if (dup1) {
//         printf("Test 1 (Regular string): %s\n", dup1);
//         free(dup1);  // Don't forget to free the memory
//     } else {
//         printf("Test 1 failed: Memory allocation failed\n");
//     }

//     // Test 2: Empty string
//     char str2[] = "";
//     char *dup2 = ft_strdup(str2);
//     if (dup2) {
//         printf("Test 2 (Empty string): '%s'\n", dup2);  // Should print ''
//         free(dup2);
//     } else {
//         printf("Test 2 failed: Memory allocation failed\n");
//     }

//     return 0;
// }
