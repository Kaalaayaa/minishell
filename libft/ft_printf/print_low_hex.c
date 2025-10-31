/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_low_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatela <kchatela@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:07:54 by kchatela          #+#    #+#             */
/*   Updated: 2025/01/30 15:07:55 by kchatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_low_hex(unsigned long long nb)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
	{
		count += print_low_hex(nb / 16);
		count += print_low_hex(nb % 16);
	}
	else
		count += print_char(base[nb % 16]);
	return (count);
}
