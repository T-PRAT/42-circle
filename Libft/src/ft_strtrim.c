/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 11:29:57 by tprat        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/10 11:57:40 by tprat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		check_char(char c, char const *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	char	*str;

	i = -1;
	len = 0;
	while (s1[++i])
		if (check_char(s1[i], set))
			len++;
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (0);
	i = -1;
	len = 0;
	while (s1[++i])
	{
		if (check_char(s1[i], set))
		{
			str[len] = s1[i];
			len++;
		}
	}
	str[len] = 0;
	return (str);
}
