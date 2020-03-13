/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:58:05 by tprat             #+#    #+#             */
/*   Updated: 2020/03/12 23:35:15 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *al, ...)
{
	t_arg	*arg;
	va_list	ap;
	int		c;

	arg = 0;
	if (!(ft_strchr(al, '%')))
	{
		ft_putstr_fd((char *)al, 1);
		return (ft_strlen(al));
	}
	va_start(ap, al);
	if (!(arg = create_list(al, ap, arg)))
		return (free_list(arg));
	va_end(ap);
	if (!(apply_flags(arg)))
		return (free_list(arg));
	c = print_all(al, arg);
	free_list(arg);
	return (c);
}
