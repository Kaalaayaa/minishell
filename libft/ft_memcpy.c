/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatela <kchatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:25:09 by kchatela          #+#    #+#             */
/*   Updated: 2024/12/02 12:04:53 by kchatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*temp_dst;
	unsigned char	*temp_src;

	if (!dst && !src)
	{
		return (NULL);
	}
	temp_dst = (unsigned char *) dst;
	temp_src = (unsigned char *) src;
	while (n > 0)
	{
		*temp_dst = *temp_src;
		temp_dst++;
		temp_src++;
		n--;
	}
	return (dst);
}

/*#include <stdio.h>
#include <string.h> // For memcmp (optional, for comparison)

void *ft_memcpy(void *dst, const void *src, size_t n);
int main() {
    // Test 1: Basic memory copy with integer arrays
    int src[] = {1, 2, 3, 4, 5};
    int dst[5] = {0};  // Destination array
    size_t n = 5 * sizeof(int); // Number of bytes to copy (5 integers)
    
    // Before memcpy, print source and destination
    printf("Before memcpy:\n");
    printf("Source: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", src[i]);
    }
    printf("\nDestination: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", dst[i]);
    }
    printf("\n");

    // Copy memory using our custom ft_memcpy
    ft_memcpy(dst, src, n);

    // After memcpy, print destination
    printf("\nAfter ft_memcpy:\n");
    printf("Source: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", src[i]);
    }
    printf("\nDestination: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", dst[i]);
    }
    printf("\n");

    // Verify correctness (optional)
    if (memcmp(src, dst, n) == 0) {
        printf("Memory copy successful! (Using memcmp for validation)\n");
    } else {
        printf("Memory copy failed.\n");
    }

    // Test 2: Edge case with zero bytes (n = 0)
    int dst2[5];
    ft_memcpy(dst2, src, 0);  // No data should be copied
    
    printf("\nAfter copying 0 bytes:\n");
    printf("Source: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", src[i]);
    }
    printf("\nDestination: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", dst2[i]);
    }
    printf("\n");

    return 0;
}*/