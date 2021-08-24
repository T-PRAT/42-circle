/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:03:46 by rkowalsk          #+#    #+#             */
/*   Updated: 2020/02/17 15:55:43 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	normal_case(int n, int fd)
{
	int		decades;
	int		already_in;
	char	num;

	already_in = 0;
	decades = 1000000000;
	if (n < 0)
	{
		n = -n;
		write(fd, "-", 1);
	}
	while (decades)
	{
		if (already_in == 1 || n / decades != 0)
		{
			num = n / decades + '0';
			write(fd, &num, 1);
			already_in = 1;
		}
		n %= (long)decades;
		decades /= 10;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n == 0)
		write(fd, "0", 1);
	else
	{
		normal_case(n, fd);
	}
}
