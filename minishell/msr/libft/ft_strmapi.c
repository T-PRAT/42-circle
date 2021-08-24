/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:38:44 by rkowalsk          #+#    #+#             */
/*   Updated: 2020/02/17 15:56:29 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	i = 0;
	if (!s || !f)
		return (NULL);
	while (s[i])
		i++;
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	j = 0;
	while (j < i)
	{
		str[j] = f(j, s[j]);
		j++;
	}
	str[j] = '\0';
	return (str);
}
