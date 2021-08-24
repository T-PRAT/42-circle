/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:52:26 by rkowalsk          #+#    #+#             */
/*   Updated: 2020/02/17 15:55:22 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	normal(unsigned char *dst, unsigned char *src, size_t len)
{
	int	i;

	i = 0;
	while (i < (int)len)
	{
		dst[i] = src[i];
		i++;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*src_str;
	unsigned char	*dst_str;
	int				i;

	if (!dst && !src)
		return (NULL);
	src_str = (unsigned char *)src;
	dst_str = (unsigned char *)dst;
	if (src_str == dst_str)
		return (dst_str);
	if (src < dst)
	{
		i = (int)len - 1;
		while (i >= 0)
		{
			dst_str[i] = src_str[i];
			i--;
		}
	}
	else
		normal(dst_str, src_str, len);
	return (dst);
}
