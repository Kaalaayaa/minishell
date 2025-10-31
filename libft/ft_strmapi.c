/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatela <kchatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:08:16 by kchatela          #+#    #+#             */
/*   Updated: 2024/11/29 14:50:28 by kchatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*newstr;

	i = 0;
	newstr = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!newstr)
	{
		return (NULL);
	}
	while (i < ft_strlen(s))
	{
		newstr[i] = (*f)(i, s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

/*#include <stdio.h>
char to_uppercase(unsigned int index, char c) {
    (void)index;  // We don't use the index in this case.
    return (char)ft_toupper((unsigned char)c);  // Convert to uppercase
}

int main(void) {
    // Test string
    char *result = ft_strmapi("Kalaya", to_uppercase);
    
    if (result) {
        printf("Result: %s\n", result);  // Expected output: "KALAYA"
        free(result);  // Don't forget to free the allocated memory!
    } else {
        printf("Memory allocation failed\n");
    }

    return 0;
}*/