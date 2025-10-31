/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatela <kchatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:34:47 by kchatela          #+#    #+#             */
/*   Updated: 2024/12/02 12:17:35 by kchatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*str1;
	unsigned char		*str2;
	size_t				i;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		i++;
	}
	return (0);
}

/*int main()
{
    // Test 1: Identical memory blocks
    char s1[] = "hello";
    char s2[] = "hello";
    int result = ft_memcmp(s1, s2, 5);  // Compare the first 5 bytes
    printf("Test 1 result: %d\n", result);  // Expected: 0 (identical)

    // Test 2: Different memory blocks (same length)
    char s3[] = "hello";
    char s4[] = "hellx";
    result = ft_memcmp(s3, s4, 5);  // Compare the first 5 bytes
    printf("Test 2 result: %d\n", result);  
    // Expected: non-zero (difference in last byte)

    // Test 3: Different lengths, compare first 3 bytes
    char s5[] = "hello";
    char s6[] = "helium";
    result = ft_memcmp(s5, s6, 3);  // Compare the first 3 bytes
    printf("Test 3 result: %d\n", result);  
    // Expected: 0 (same for first 3 bytes)

    // Test 4: Compare different sizes (not same length)
    char s7[] = { 1, 2, 3, 4, 5 };
    char s8[] = { 1, 2, 3, 4, 6 };
    result = ft_memcmp(s7, s8, 5);  // Compare the first 5 bytes
    printf("Test 4 result: %d\n", result);  
    // Expected: negative value (5 - 6 = -1)

    // Test 5: Edge case - Compare 0 bytes
    result = ft_memcmp(s1, s2, 0);  // Compare 0 bytes
    printf("Test 5 result: %d\n", result);  
    // Expected: 0 (no difference because no bytes are compared)

    // Test 6: Use standard memcmp to compare and check consistency
    result = memcmp(s1, s2, 5);
    int standard_result = memcmp(s1, s2, 5);
    printf("Test 6 (standard memcmp) result: %d\n", standard_result);  
    // Expected: 0 (should match your memcmp)

    return 0;
}*/