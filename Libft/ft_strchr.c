/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 18:21:43 by tprat        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/09 18:21:45 by tprat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*str2;

	str2 = (char *)str;
	i = 0;
	while (str[i] != c && str[i])
		i++;
	if (str[i] == 0)
	{
		if (c == 0)
			return (str2 + i);
		else
			return (0);
	}
	else
		return (str2 + i);
}
