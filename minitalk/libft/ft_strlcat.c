/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:40:05 by tprat             #+#    #+#             */
/*   Updated: 2020/03/12 01:55:07 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	if (size <= i)
	{
		while (src[j])
			j++;
		return (size + j);
	}
	while (src[j])
	{
		if (size >= i)
			dst[i] = src[j];
		i++;
		j++;
		if (i == size)
			dst[i - 1] = 0;
	}
	dst[i] = 0;
	return (i);
}
