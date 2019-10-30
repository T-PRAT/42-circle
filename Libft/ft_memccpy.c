/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 11:44:38 by tprat        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/30 16:13:57 by tprat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str2 = (unsigned char *)dest;
	str1 = (unsigned char *)src;
	i = 0;
	if (n == 0)
		return (NULL);
	while (n >= i && str1[i] != (unsigned char)c)
	{
		str2[i] = str1[i];
		i++;
	}
	if (str1[i] == (unsigned char)c)
	{
		str2[i] = str1[i];
		return (str2 + i + 1);
	}
	return (NULL);
}
