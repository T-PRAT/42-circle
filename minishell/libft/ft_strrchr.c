/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:22:44 by tprat             #+#    #+#             */
/*   Updated: 2020/03/12 01:55:44 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*str2;

	i = 0;
	while (str[i])
		i++;
	str2 = (char *)str;
	while (str[i] != c && i > 0)
		i--;
	if (i == 0)
	{
		if (str[i] == c)
			return (str2);
		else
			return (0);
	}
	return (str2 + i);
}
