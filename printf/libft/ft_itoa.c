/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 18:23:16 by tprat        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/29 18:03:38 by tprat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		nbr_len(int n)
{
	int len;

	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa2(char *res, int n)
{
	int		len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	len += nbr_len(n);
	if (!(res = malloc(sizeof(char) * (len + 1))))
		return (0);
	res[len] = 0;
	while (n > 0)
	{
		len--;
		res[len] = (n % 10) + 48;
		n /= 10;
	}
	if (len == 1)
		res[0] = '-';
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;

	res = 0;
	if (n == -2147483648)
		res = ft_strdup("-2147483648");
	else if (n == 0)
		res = ft_strdup("0");
	else
	{
		if (!(ft_itoa2(res, n)))
			return (0);
		res = ft_itoa2(res, n);
	}
	return (res);
}
