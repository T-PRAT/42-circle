/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:58:05 by tprat             #+#    #+#             */
/*   Updated: 2020/02/25 19:37:51 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *al, ...)
{
	t_arg	*arg;
	va_list	ap;
	int		c;

	va_start(ap, al);
	if (!(arg = create_list(al, ap)))
		return (0);
	va_end(ap);
	if (!(apply_flags(arg)))
		return (0);
	c = print_all(al, arg);
	free_list(arg);
	return (c);
}
