/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatela <kchatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:06:11 by kchatela          #+#    #+#             */
/*   Updated: 2025/05/20 18:36:53 by kchatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "../libft.h"

int	ft_printf(const char *input, ...);
int	print_string(char *str);
int	print_char(char c);
int	print_signed_int(int d);
int	print_unsigned_int(unsigned int u);
int	print_up_hex(unsigned long long nb);
int	print_low_hex(unsigned long long nb);
int	print_pointer(unsigned long long p);

#endif
