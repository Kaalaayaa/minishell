/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatela <kchatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:20:08 by kchatela          #+#    #+#             */
/*   Updated: 2024/11/29 15:22:01 by kchatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}

/*
#include <stdio.h>

int main()
{
    // Test case 1: Normal case
    char *s1 = "Hello, World!";
    char *result1 = ft_substr(s1, 7, 5);  // Expected: "World"
    printf("Test 1: %s\n", result1);
    free(result1);

    // Test case 2: Start index is greater than the string length
    char *result2 = ft_substr(s1, 20, 5);  // Expected: ""
    printf("Test 2: %s\n", result2);
    free(result2);

    // Test case 3: Start index is within the string, but the length is too large
    char *result3 = ft_substr(s1, 7, 100);  // Expected: "World!"
    printf("Test 3: %s\n", result3);
    free(result3);

    // Test case 4: Empty string input
    char *s4 = "";
    char *result4 = ft_substr(s4, 0, 5);  // Expected: ""
    printf("Test 4: %s\n", result4);
    free(result4);

    // Test case 5: Start index is at the beginning
    char *result5 = ft_substr(s1, 0, 5);  // Expected: "Hello"
    printf("Test 5: %s\n", result5);
    free(result5);

    // Test case 6: Substring starts at the end of the string
    char *result6 = ft_substr(s1, 13, 5);  // Expected: ""
    printf("Test 6: %s\n", result6);
    free(result6);

    return 0;
}*/
