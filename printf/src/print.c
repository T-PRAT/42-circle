/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:39:11 by tprat             #+#    #+#             */
/*   Updated: 2020/03/12 00:29:27 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	czero(t_arg *current)
{
	int c;

	c = 0;
	c++;
	if (!(current->blank))
		ft_putchar_fd(0, 1);
	else if (current->blank > 0)
	{
		while (--current->blank)
		{
			ft_putchar_fd(' ', 1);
			c++;
		}
		ft_putchar_fd(0, 1);
	}
	else
	{
		ft_putchar_fd(0, 1);
		while (++current->blank)
		{
			ft_putchar_fd(' ', 1);
			c++;
		}
	}
	return (c);
}

int	print_res(t_arg *current)
{
	int c;

	c = 0;
	if (current->res[0] == '\0' && current->type == 'c')
		c += czero(current);
	else
	{
		ft_putstr_fd(current->res, 1);
		c += ft_strlen(current->res);
	}
	return (c);
}

int	print_all(const char *al, t_arg *current)
{
	int i;
	int	c;

	i = 0;
	c = 0;
	while (al[i])
	{
		if (al[i] == '%')
		{
			i++;
			c += print_res(current);
			current = current->next;
			while (!(ft_strchr("cspdiuxX%", al[i])))
				i++;
			i++;
		}
		else
		{
			ft_putchar_fd(al[i], 1);
			c++;
			if (al[i])
				i++;
		}
	}
	return (c);
}
