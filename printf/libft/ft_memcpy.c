/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:17:41 by tprat             #+#    #+#             */
/*   Updated: 2020/03/12 01:53:35 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *pdst, const void *psrc, size_t n)
{
	size_t	i;
	char	*dst;
	char	*src;

	i = 0;
	dst = pdst;
	src = (char *)psrc;
	if (dst == 0 && src == 0)
		return (0);
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return (pdst);
}
