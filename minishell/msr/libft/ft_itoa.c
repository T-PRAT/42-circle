/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:30:35 by rkowalsk          #+#    #+#             */
/*   Updated: 2020/02/17 15:54:51 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(int n)
{
	long int	fat_n;
	int			size;

	fat_n = (long int)n;
	size = 0;
	if (fat_n == 0)
		return (1);
	if (fat_n < 0)
	{
		fat_n *= -1;
		size++;
	}
	while (fat_n)
	{
		fat_n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int			size;
	char		*str;
	int			i;
	long int	fat_n;

	fat_n = (long int)n;
	i = 0;
	size = get_size(fat_n);
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[i++] = '-';
		fat_n = -fat_n;
	}
	str[size--] = '\0';
	while (fat_n)
	{
		str[size--] = fat_n % 10 + '0';
		fat_n /= 10;
	}
	return (str);
}
