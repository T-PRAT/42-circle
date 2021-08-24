/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:03:08 by rkowalsk          #+#    #+#             */
/*   Updated: 2020/02/17 15:56:18 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;
	size_t	j;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (len_dst >= size)
		return (len_src + size);
	j = len_dst;
	i = 0;
	while (j < size - 1 && src[i])
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (len_dst + len_src);
}
