/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 10:53:16 by tprat        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/22 15:09:04 by tprat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *pdst, const void *psrc, size_t len)
{
	size_t	i;
	char	tmp[len];
	char	*dst;
	char	*src;

	i = 0;
	dst = pdst;
	src = (char *)psrc;
	while (i < len)
	{
		tmp[i] = src[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		dst[i] = tmp[i];
		i++;
	}
	return (pdst);
}
