/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatela <kchatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:35:13 by kchatela          #+#    #+#             */
/*   Updated: 2024/12/02 15:18:56 by kchatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
	{
		return ((char *)haystack);
	}
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] != '\0' && needle[j] == haystack[i + j]
			&& (i + j) < len)
		{
			j++;
		}
		if (needle[j] == '\0')
		{
			return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>

int main(void)
{
    // Test 1: Basic match within bounds
    char haystack1[] = "Hello, world!";
    char needle1[] = "world";
    printf("Test 1: %s\n", ft_strnstr(haystack1, needle1, 13));
	// Should print: world!

    // Test 2: Match at the very beginning
    char haystack2[] = "Hello, world!";
    char needle2[] = "Hello";
    printf("Test 2: %s\n", ft_strnstr(haystack2, needle2, 13));  
	// Should print: Hello, world!

    // Test 3: Match at the very end
    char haystack3[] = "Hello, world!";
    char needle3[] = "world";
    printf("Test 3: %s\n", ft_strnstr(haystack3, needle3, 13));  
	// Should print: world!

    // Test 4: Needle is longer than haystack
    char haystack4[] = "Hi!";
    char needle4[] = "Hello";
    printf("Test 4: %s\n", ft_strnstr(haystack4, needle4, 3));  
	// Should print: (null)

    // Test 5: Needle not found
    char haystack5[] = "Hello, world!";
    char needle5[] = "abc";
    printf("Test 5: %s\n", ft_strnstr(haystack5, needle5, 13));  
	// Should print: (null)

    // Test 6: Needle is an empty string
    char haystack6[] = "Hello, world!";
    char needle6[] = "";
    printf("Test 6: %s\n", ft_strnstr(haystack6, needle6, 13)); 
	// Should print: Hello, world!

    return 0;
}*/
