/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 09:56:21 by tprat             #+#    #+#             */
/*   Updated: 2020/03/12 01:55:13 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	char	*dst;

	dst = (char *)dest;
	i = 0;
	if (!(dest && src))
		return (0);
	if (size == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (src[i] && size - 1 > i)
	{
		dst[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	i = 0;
	while (src[i])
		i++;
	return (i);
}
