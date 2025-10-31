/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatela <kchatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:17:26 by kchatela          #+#    #+#             */
/*   Updated: 2024/11/29 15:32:15 by kchatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	char_c;

	char_c = (char) c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == char_c)
		{
			return ((char *)&s[i]);
		}
		i--;
	}
	return (NULL);
}

/*#include <stdio.h>

int main(void)
{
    char s[] = "Kalaya";
    char c = '\0';
    
    char *result = ft_strrchr(s, c);
    
    if (result != NULL)
    {
        printf("Character '%c' found at position: %ld\n", c, result - s);
    }
    else
    {
        printf("Character '%c' not found\n", c);
    }

    return 0;
}
*/
