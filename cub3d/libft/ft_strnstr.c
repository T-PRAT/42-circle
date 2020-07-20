/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:02:31 by tprat             #+#    #+#             */
/*   Updated: 2020/03/12 01:55:38 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t size)
{
	int		i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	if (to_find[i] == '\0')
		return ((char *)str);
	while (str[i] && j < size)
	{
		k = i;
		while (str[k] == to_find[j] && k < size)
		{
			k++;
			j++;
			if (to_find[j] == '\0')
				return ((char *)str + (k - j));
		}
		j = 0;
		i++;
	}
	return (0);
}
