/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatela <kchatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:07:33 by kchatela          #+#    #+#             */
/*   Updated: 2024/11/25 14:49:30 by kchatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
	{
		return (c + 32);
	}
	return (c);
}

/*#include <stdio.h>

int main(void)
{
    printf("lowercase: %c\n", ft_tolower('a' - 1));
    printf("lowercase: %c\n", ft_tolower('a'));
    printf("lowercase: %c\n", ft_tolower('A'));
}*/
