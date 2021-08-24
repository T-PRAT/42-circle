/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:40:41 by rkowalsk          #+#    #+#             */
/*   Updated: 2020/02/17 15:55:16 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned long	i;
	char			*dst_tab;
	char			*src_tab;

	if (!dst && !src)
		return (NULL);
	dst_tab = (char *)dst;
	src_tab = (char *)src;
	i = 0;
	while (i < n)
	{
		dst_tab[i] = src_tab[i];
		i++;
	}
	return (dst);
}
