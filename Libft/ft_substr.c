/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_substr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 10:44:35 by tprat        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/22 17:28:15 by tprat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	if (!(str = malloc(sizeof(char) * len + 1)))
		return (0);
	if (start >= i)
		return (0);
	i = 0;
	while (s[i] && i < len && s[start])
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = 0;
	return (str);
}
