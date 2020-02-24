/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:58:05 by tprat             #+#    #+#             */
/*   Updated: 2020/02/24 18:58:07 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *al, ...)
{
	t_arg	*arg;
	va_list	ap;

	va_start(ap, al);
	if (!(arg = create_list(al, ap)))
		return (0);
	if (!(apply_flags(arg)))
		return (0);
	while (arg)
	{
		printf("type:%c\n", arg->type);
		printf("zero:%d\n", arg->zero);
		printf("prec:%d\n", arg->prec);
		printf("blank:%d\n", arg->blank);
		printf("res:%s\n", arg->res);
		arg = arg->next;
	}
	va_end(ap);
	return (0);
}
