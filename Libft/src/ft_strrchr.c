/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 18:22:44 by tprat        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/09 18:23:37 by tprat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*str2;

	i = 0;
	while (str[i])
		i++;
	i--;
	str2 = (char *)str;
	while (str[i] != c && str[i])
		i--;
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
