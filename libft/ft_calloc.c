/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatela <kchatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:50:43 by kchatela          #+#    #+#             */
/*   Updated: 2024/12/02 15:17:01 by kchatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t				i;
	unsigned char		*tmp;

	i = 0;
	if (count == (size_t)-1 || size == (size_t)-1
		|| (count && size > SIZE_MAX / count))
	{
		return (NULL);
	}
	tmp = malloc(count * size);
	if (!tmp)
	{
		return (NULL);
	}
	while (i < count * size)
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}

/*#include <stdio.h>

int main() {
    size_t count = 5;
    size_t size = sizeof(int);  // Size of each element (e.g., int)
    
    // Test 1: Allocate memory using ft_calloc
    int *arr = ft_calloc(count, size);

    // Check if memory allocation was successful
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;  // Return non-zero to indicate error
    }

    // Test 2: Check if the allocated memory is initialized to 0
    printf("Allocated memory values (should be 0 for all elements):\n");
    size_t i = 0;
    while (i < count) {
        printf("arr[%zu] = %d\n", i, arr[i]); // prints 0
        i++;
    }

    // Test 3: Modify values in the allocated memory
    i = 0;
    while (i < count) {
        arr[i] = (int)(i + 1); //Set elements to non-zero value(1, 2, 3)
        i++;
    }

    printf("\nModified values in the allocated memory:\n");
    i = 0;
    while (i < count) {
        printf("arr[%zu] = %d\n", i, arr[i]); //prints 1, 2, 3, etc.
        i++;
    }

    // Test 4: Free the allocated memory
    free(arr);
    printf("\nMemory freed successfully.\n");

    return 0;  // Return 0 to indicate success
}*/
