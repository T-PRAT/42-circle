/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 08:58:47 by rkowalsk          #+#    #+#             */
/*   Updated: 2020/02/17 15:56:36 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len)
	{
		if (*haystack == *needle)
		{
			i = 0;
			while (haystack[i] == needle[i] && needle[i] && (size_t)i < len)
				i++;
			if (!needle[i])
				return ((char *)haystack);
		}
		haystack++;
		len--;
	}
	return (NULL);
}
