/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 23:22:45 by tprat             #+#    #+#             */
/*   Updated: 2020/02/13 04:07:02 by tprat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *al, ...)
{
	t_arg	*arg;
	va_list	ap;

	va_start(ap, al);
	if (!(arg = get_flags(al)))
		return (0);
	if (!(get_args(ap, arg)))
		return (0);
	while (arg)
	{
		printf("type:%c\n", arg->type);
		printf("res:%s\n", arg->res);
		arg = arg->next;
	}
	va_end(ap);
	return (0);
}
