/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 10:53:16 by tprat        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/09 18:20:33 by tprat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *pdst, const void *psrc, size_t len)
{
	size_t	i;
	char	*dst;
	char	*src;

	i = 0;
	dst = pdst;
	src = (char *)psrc;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	return (pdst);
}
