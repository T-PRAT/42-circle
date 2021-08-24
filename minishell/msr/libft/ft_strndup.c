/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 12:07:23 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/04/14 14:19:31 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, unsigned int size)
{
	unsigned int	len;
	unsigned int	i;
	char			*str;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	if (size < len)
		len = size;
	str = malloc(sizeof(*src) * (len + 1));
	if (str != NULL)
	{
		while (i < len)
		{
			str[i] = src[i];
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
