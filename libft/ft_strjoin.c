/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatela <kchatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:25:52 by kchatela          #+#    #+#             */
/*   Updated: 2024/11/27 12:53:36 by kchatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	result = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char)));
	if (!result)
		return (NULL);
	while (s1[i])
	{
		result[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (s2[i])
	{
		result[j] = s2[i];
		j++;
		i++;
	}
	result[j] = '\0';
	return (result);
}

/*#include "stdio.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h> // For free()

int main() {
    // Test 1: Normal case
    char *str1 = "Kalaya ";
    char *str2 = "Chatelain";
    char *result = ft_strjoin(str1, str2);
    if (result) {
        printf("Test 1: %s\n", result); // Expected: "Hello, world!"
        free(result);
    } else {
        printf("Test 1: Memory allocation failed\n");
    }

    // Test 2: One empty string
    char *str3 = "";
    char *str4 = "Kalaya";
    result = ft_strjoin(str3, str4);
    if (result) {
        printf("Test 2: %s\n", result); // Expected: "Hello!"
        free(result);
    } else {
        printf("Test 2: Memory allocation failed\n");
    }

    // Test 3: Both strings are empty
    char *str5 = "";
    char *str6 = "";
    result = ft_strjoin(str5, str6);
    if (result) {
        printf("Test 3: %s\n", result); // Expected: ""
        free(result);
    } else {
        printf("Test 3: Memory allocation failed\n");
    }
}*/
