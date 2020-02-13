/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 00:40:41 by tprat             #+#    #+#             */
/*   Updated: 2020/02/13 00:52:35 by tprat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	u_nbr_len(unsigned int n)
{
	unsigned int len;

	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char			*ft_utoa2(char *res, unsigned int n)
{
	unsigned int		len;

	len = 0;
	len += u_nbr_len(n);
	if (!(res = malloc(sizeof(char) * (len + 1))))
		return (0);
	res[len] = 0;
	while (n > 0)
	{
		len--;
		res[len] = (n % 10) + 48;
		n /= 10;
	}
	return (res);
}

char			*ft_utoa(unsigned int n)
{
	char	*res;

	res = 0;
	if (n == 0)
		res = ft_strdup("0");
	else
	{
		if (!(res = ft_utoa2(res, n)))
			return (0);
	}
	return (res);
}
