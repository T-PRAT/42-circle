/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 15:40:05 by tprat        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/22 16:03:13 by tprat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	if (i >= size)
	{
		while (src[j])
			j++;
		return (size + j);
	}
	while (src[j])
	{
		if (i < size)
			dst[i] = src[j];
		if (i == size)
			dst[i - 1] = 0;
		i++;
		j++;
	}
	return (i);
}
