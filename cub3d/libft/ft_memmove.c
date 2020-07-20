/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 10:53:16 by tprat             #+#    #+#             */
/*   Updated: 2020/03/12 01:53:41 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *pdst, const void *psrc, size_t len)
{
	size_t	i;
	char	*src;
	char	*dst;

	i = len - 1;
	dst = pdst;
	src = (char *)psrc;
	if (dst > src)
	{
		while (i + 1 > 0)
		{
			dst[i] = src[i];
			i--;
		}
	}
	else if (dst < src)
	{
		i = 0;
		while (i < len)
		{
			dst[i] = src[i];
			i++;
		}
	}
	return (pdst);
}
