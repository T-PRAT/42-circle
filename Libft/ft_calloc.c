/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_calloc.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 16:57:11 by tprat        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/22 14:03:21 by tprat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	len;

	len = size * count;
	if (!(str = malloc(len)))
		return (0);
	len--;
	while (len > 0)
	{
		str[len] = 0;
		len--;
	}
	str[0] = 0;
	return ((void *)str);
}
