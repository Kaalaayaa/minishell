/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatela <kchatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:31:58 by kchatela          #+#    #+#             */
/*   Updated: 2024/11/27 15:39:22 by kchatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		len;
	char	*result;

	start = 0;
	end = ft_strlen(s1) - 1;
	if (!s1)
		return (ft_strdup(""));
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end >= start && ft_strchr(set, s1[end]))
		end--;
	len = end - start + 1;
	result = (char *)malloc(len + 1 * sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1 + start, len + 1);
	return (result);
}

/*#include <stdio.h>

int main(void)
{
    // Test case 1: Basic trimming
    char str1[] = "ababaHello, World!abbba";
    char set1[] = "ab";
    char *result1 = ft_strtrim(str1, set1);
    if (result1)
    {
        printf("Trimmed string 1: '%s'\n", result1);
        free(result1); // Free the allocated memory
    }
    else
    {
        printf("Memory allocation failed for string 1.\n");
    }

    // Test case 2: No characters to trim
    char str2[] = "Hello, World!";
    char set2[] = " ";
    char *result2 = ft_strtrim(str2, set2);
    if (result2)
    {
        printf("Trimmed string 2: '%s'\n", result2);
        free(result2);
    }
    else
    {
        printf("Memory allocation failed for string 2.\n");
    }

    // Test case 3: All characters are in the set
    char str3[] = "!!!";
    char set3[] = "!";
    char *result3 = ft_strtrim(str3, set3);
    if (result3)
    {
        printf("Trimmed string 3: '%s'\n", result3);
        free(result3);
    }
    else
    {
        printf("Memory allocation failed for string 3.\n");
    }

    // Test case 4: Empty string input
    char str4[] = "";
    char set4[] = " ";
    char *result4 = ft_strtrim(str4, set4);
    if (result4)
    {
        printf("Trimmed string 4: '%s'\n", result4);
        free(result4);
    }
    else
    {
        printf("Memory allocation failed for string 4.\n");
    }

    return 0;
}*/
