/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatela <kchatela@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:07:31 by kchatela          #+#    #+#             */
/*   Updated: 2025/01/30 15:07:31 by kchatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_signed_int(int d)
{
	int	count;
	int	temp;

	count = 0;
	temp = d;
	if (temp == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	if (temp < 0)
	{
		count++;
	}
	while (temp)
	{
		temp = temp / 10;
		count++;
	}
	ft_putnbr_fd(d, 1);
	return (count);
}
