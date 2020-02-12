/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_args.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprat <tprat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/12 03:23:48 by tprat        #+#   ##    ##    #+#       */
/*   Updated: 2020/02/12 05:05:24 by tprat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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
	}
	return (res);
}

int		get_args(va_list ap, t_arg *arg)
{
	while (arg)
	{
		if (!(arg->res = choose_type(arg, ap)))
		arg = arg->next;
	}
	return (1);
}
