/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:15:21 by rkowalsk          #+#    #+#             */
/*   Updated: 2020/02/17 15:56:50 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	unsigned int	max_len;
	unsigned int	i;
	char			*new_str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		new_str = malloc(sizeof(char));
		if (new_str)
			new_str[0] = '\0';
		return (new_str);
	}
	max_len = 0;
	while (s[max_len + start] && max_len < len)
		max_len++;
	new_str = (char *)malloc((1 + max_len) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < max_len)
		new_str[i++] = s[start++];
	new_str[i] = '\0';
	return (new_str);
}
