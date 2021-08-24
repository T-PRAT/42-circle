/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:35:23 by rkowalsk          #+#    #+#             */
/*   Updated: 2020/02/17 15:56:09 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		len;
	int		i;
	char	*str;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	str = malloc(sizeof(*src) * (len + 1));
	if (str != NULL)
	{
		while (src[i])
		{
			str[i] = src[i];
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
