/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:39:11 by tprat             #+#    #+#             */
/*   Updated: 2020/02/25 18:18:09 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			ft_putstr_fd(current->res, 1);
			c += ft_strlen(current->res);
			current = current->next;
			while (!(ft_strchr("cspdiuxX%", al[i])))
				i++;
			i++;
		}
		else
		{
			ft_putchar_fd(al[i], 1);
			c++;
		}
		if (al[i])
			i++;
	}
	return (i);
}
