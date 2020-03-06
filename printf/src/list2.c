/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 18:56:15 by tprat             #+#    #+#             */
/*   Updated: 2020/03/06 23:49:05 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	custom_atoi(const char *al, t_arg *arg, va_list ap)
{
	int i;

	i = 0;
	if (al[i] == '-')
	{
		while (al[i] == '-')
			i++;
		if (al[i] == '*')
		{
			arg->blank = va_arg(ap, int);
			if (arg->blank > 0)
				arg->blank *= -1;
		}
		else
			arg->blank = ft_atoi(al + i - 1);
	}
	else if (ft_isdigit(al[i]))
		arg->blank = ft_atoi(al + i);
	return (i);
}

int	fill_flags(const char *al, t_arg *arg, va_list ap)
{
	int i;

	i = 0;
	if (al[i] == '0')
	{
		(al[++i] == '*') ? (arg->zero = va_arg(ap, int)) :
		(arg->zero = ft_atoi(al + i));
		while (ft_isdigit(al[i]))
			i++;
		if (al[i] == '*')
			i++;
	}
	custom_atoi(al + i, arg, ap);
	if (al[i] == '*')
		arg->blank = va_arg(ap, int);
	while (ft_isdigit(al[i]) || al[i] == '*' || al[i] == '-')
		i++;
	if (al[i] == '.')
	{
		(al[++i] == '*') ? (arg->prec = va_arg(ap, int)) :
		(arg->prec = ft_atoi(al + i));
		if (arg->prec == 0)
			arg->prec = -1;
	}
	while (ft_isdigit(al[i]) || al[i] == '.' || al[i] == '-' || al[i] == '*')
		i++;
	if (ft_strchr("cspdiuxX%", al[i]))
		arg->type = al[i];
	else
		return (0);
	if (arg->zero < 0)
		arg->blank = arg->zero;
	if (arg->zero > arg->prec && arg->zero > arg->blank > 0 && arg->prec > 0)
		arg->blank = arg->zero;
	return (1);
}
