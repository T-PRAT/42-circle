/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:29:57 by tprat             #+#    #+#             */
/*   Updated: 2020/03/12 01:55:51 by tprat            ###   ########lyon.fr   */
/*                                                                            */
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

int		str_end(char const *s1, char const *set)
{
	int c;

	c = 0;
	while (s1[c])
		c++;
	c--;
	while (check_char(s1[c], set) == 0 && c > 0)
		c--;
	c++;
	return (c);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = 0;
	if ((!s1) || (!(set)))
		return (0);
	while (check_char(s1[i], set) == 0 && s1[i])
		i++;
	if (s1[i] == 0)
		i = -1;
	if (!(str = malloc(sizeof(char) * (1 + str_end(s1, set) - i))))
		return (0);
	while (i < str_end(s1, set) && i >= 0)
	{
		str[j] = s1[i];
		j++;
		i++;
	}
	str[j] = 0;
	return (str);
}
