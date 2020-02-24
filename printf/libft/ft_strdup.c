/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:53:44 by tprat             #+#    #+#             */
/*   Updated: 2020/02/24 17:49:13 by tprat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "stdlib.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;

	i = 0;
	if (!(src))
		return (0);
	while (src[i])
		i++;
	if (!(dest = malloc((i + 1) * sizeof(char))))
		return (0);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
