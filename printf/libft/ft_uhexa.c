/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uhexa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 01:43:42 by tprat             #+#    #+#             */
/*   Updated: 2020/02/13 02:27:16 by tprat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	fill_dst(char c, char *dst, unsigned long long x)
{
	static unsigned long  long	j;

	if (!(j) || x == 1)
		j = 0;
	if (x != 1)
	{
		dst[j] = c;
		j++;
	}
}

void	ft_putnbr_base(unsigned long long nbr, char *base, char *dst)
{
	unsigned long long			b;

	b = 0;
	while (base[b])
		b++;
	if (nbr < b && nbr >= 0)
		fill_dst(base[nbr % b], dst, 2);
	if (nbr > b - 1)
	{
		ft_putnbr_base(nbr / b, base, dst);
		ft_putnbr_base(nbr % b, base, dst);
	}
}

char	*ft_uhexa(unsigned long long i, char c)
{
	char						*dst;
	unsigned long long			x;
	unsigned long long			j;

	j = i;
	x = 1;
	while (j > 16)
	{
		x++;
		j = j / 16;
	}
	if (!(dst = malloc(sizeof(char) * x) + 1))
		return (0);
	dst[x] = '\0';
	ft_putnbr_base(i, "0123456789ABCDEF", dst);
	fill_dst(c, dst, 1);
	x = -1;
	if (c == 'x')
		while (dst[++x] != '\0')
			dst[x] = ft_tolower(dst[x]);
	return (dst);
}
