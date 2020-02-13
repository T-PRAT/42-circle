/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 23:22:35 by tprat             #+#    #+#             */
/*   Updated: 2020/02/13 02:30:59 by tprat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*choose_type(t_arg *arg, va_list ap)
{
	char *res;

	res = 0;
	if (arg->type == 'c')
	{
		if (!(res = malloc(sizeof(char) * 2)))
			return (0);
		res[0] = va_arg(ap, int);
		res[1] = 0;
	}
	if (arg->type == 's')
		res = ft_strdup(va_arg(ap, char *));
	if (arg->type == 'd' || arg->type == 'i')
		res = ft_itoa(va_arg(ap, int));
	if (arg->type == 'u')
		res = ft_utoa(va_arg(ap, unsigned int));
	if (arg->type == 'x' || arg->type == 'X')
		res = ft_uhexa(va_arg(ap, unsigned int), arg->type);
	if (arg->type == 'p')
		res = ft_strjoin("0x", ft_uhexa(va_arg(ap, unsigned long long), 'x'));
	if (arg->type == '%')
		res = ft_strdup("%");
	return (res);
}

int		get_args(va_list ap, t_arg *arg)
{
	while (arg)
	{
		if (!(arg->res = choose_type(arg, ap)))
			return (0);
		arg = arg->next;
	}
	return (1);
}
