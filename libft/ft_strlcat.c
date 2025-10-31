/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatela <kchatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:42:56 by kchatela          #+#    #+#             */
/*   Updated: 2024/12/02 16:03:44 by kchatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;
	size_t	j;

	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	i = 0;
	j = len_dst;
	if (len_dst < size)
	{
		while (src[i] && (len_dst + i) < (size - 1))
		{
			dst[j] = src[i];
			i++;
			j++;
		}
		dst[j] = '\0';
	}
	else
		len_dst = size;
	return (len_dst + len_src);
}

/*#include <stdio.h>
#include <string.h>


int main(void)
{
    char dst[50];
    const char *src = "ca va?";
    size_t dstsize;

    // Test 1: enough space
    strcpy(dst, "Hello ");
    dstsize = 50;
    printf("Test 1: %zu (Expected: 12)\n", ft_strlcat(dst, src, dstsize)); 
    printf("Result: '%s'\n\n", dst); // Should print "Hello world!"

    //Test 2: too small
    strcpy(dst, "Hello ");
    dstsize = 10;
    printf("Test 2: %zu (Expected: 12)\n", ft_strlcat(dst, src, dstsize));
    printf("Result: '%s'\n\n", dst); // Should print "Hello ca "


    //Test 3: dst is full
    strcpy(dst, "Hello");
    dstsize = 5;
    printf("Test 3: %zu (Expected: 11)\n", ft_strlcat(dst, src, dstsize));
    printf("Result: '%s'\n\n", dst); // Should print "Hello"

    //Test 4: dst is empty
    strcpy(dst, "\0");
    dstsize = 50;
    printf("Test 4: %zu (Expected: 6)\n", ft_strlcat(dst, src, dstsize));
    printf("Result: '%s'\n\n", dst); // Should print "Hello"

     // Test case 5: dstsize is 0
    dst[0] = '\0';
    dstsize = 0;
    printf("Test 5: %zu (Expected: 6)\n", ft_strlcat(dst, src, dstsize)); 
    printf("Result: '%s'\n\n", dst); // Should print an empty string

    return 0;
}*/
