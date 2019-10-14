/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 11:44:38 by tprat        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/09 18:23:05 by tprat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *pdst, const void *psrc, int c, size_t n)
{
	size_t	i;
	char	*dst;
	char	*src;
	void	*ptr;

	i = 0;
	dst = pdst;
	src = (char *)psrc;
	while (src[i] && i < n)
	{
		if (src[i] == c)
		{
			ptr = &dst[i + 1];
			return (ptr);
		}
		dst[i] = src[i];
		i++;
	}
	return (0);
}
