/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatela <kchatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:05:50 by kchatela          #+#    #+#             */
/*   Updated: 2025/05/20 18:37:33 by kchatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"
#include <stdio.h>

int	check_format_specifier(va_list args, char specifier);

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, input);
	while (*input != '\0')
	{
		if (*input == '%')
		{
			input++;
			if (ft_strchr("cspdiuxX%", *input))
				count += check_format_specifier(args, *input);
		}
		else
		{
			ft_putchar_fd(*input, 1);
			count++;
		}
		input++;
	}
	va_end (args);
	return (count);
}

//For each specifier, the correct type is extracted using va_arg
int	check_format_specifier(va_list args, char specifier)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(args, int));
	else if (specifier == 's')
		count += print_string(va_arg(args, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += print_signed_int(va_arg(args, int));
	else if (specifier == 'u')
		count += print_unsigned_int(va_arg(args, unsigned int));
	else if (specifier == 'x')
		count += print_low_hex((unsigned long long)va_arg(args, unsigned int));
	else if (specifier == 'X')
		count += print_up_hex((unsigned long long)va_arg(args, unsigned int));
	else if (specifier == 'p')
		count += print_pointer((unsigned long long)va_arg(args, void *));
	else if (specifier == '%')
		count += print_char('%');
	return (count);
}
