/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 22:30:15 by tprat             #+#    #+#             */
/*   Updated: 2020/02/24 19:10:28 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*apply_prec(char *res, int prec)
{
	if (prec > 0)
	{
		while (prec)
		{
			if (!(res = ft_strjoin("0", res)))
				return (0);
			prec--;
		}
	}
	return (res);
}

int		apply_flags(t_arg *current)
{
	while (current)
	{
		if (current->prec)
			if (!(current->res = apply_prec(current->res, current->prec)))
				return (0);
		current = current->next;
	}
	return (1);
}
