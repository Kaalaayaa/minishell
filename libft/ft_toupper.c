/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatela <kchatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:07:18 by kchatela          #+#    #+#             */
/*   Updated: 2024/11/25 14:48:19 by kchatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		return (c - 32);
	}
	return (c);
}

/*#include <stdio.h>

int main(void)
{
    printf("uppercase: %c\n", ft_toupper('A' - 1));
    printf("uppercase: %c\n", ft_toupper('a'));
    printf("uppercase: %c", ft_toupper('A'));
}*/
