/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatela <kchatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:17:34 by kchatela          #+#    #+#             */
/*   Updated: 2024/12/02 15:47:25 by kchatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*temp_dst;
	unsigned char	*temp_src;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	temp_dst = (unsigned char *) dst;
	temp_src = (unsigned char *) src;
	i = 0;
	if (temp_dst > temp_src)
	{
		while (len--)
		{
			temp_dst[len] = temp_src[len];
		}
	}
	else
	{
		while (i < len)
		{
			temp_dst[i] = temp_src[i];
			i++;
		}
	}
	return (dst);
}
