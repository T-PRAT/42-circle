/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 22:30:15 by tprat             #+#    #+#             */
/*   Updated: 2020/03/12 01:45:13 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	apply_zero(t_arg *curr)
{
	int		i;
	char	*tmp;

	i = 0;
	while (curr->res[i])
		i++;
	curr->zero -= i;
	while (curr->zero > 0)
	{
		tmp = curr->res;
		if (curr->res[0] == '-')
		{
			if (!(curr->res = ft_strjoin("-0", curr->res + 1)))
				return (0);
		}
		else
		{
			if (!(curr->res = ft_strjoin("0", curr->res)))
				return (0);
		}
		free(tmp);
		curr->zero--;
	}
	return (1);
}

int	prec_one(t_arg *curr)
{
	if (ft_strncmp(curr->res, "0", 2) == 0 && (!(ft_strchr("sp", curr->type))))
	{
		free(curr->res);
		if (!(curr->res = ft_strdup("")))
			return (0);
	}
	else if (ft_strncmp(curr->res, "0x0", 4) == 0 &&
	curr->type == 'p')
	{
		free(curr->res);
		if (!(curr->res = ft_strdup("0x")))
			return (0);
	}
	else if (curr->type == 's')
	{
		free(curr->res);
		if (!(curr->res = ft_strdup("")))
			return (0);
	}
	return (1);
}

int	apply_flags(t_arg *curr)
{
	while (curr)
	{
		if (curr->prec == -1 && !(curr->res[0] == '\0' && curr->type == 'c'))
		{
			if (!(prec_one(curr)))
				return (0);
		}
		if (curr->prec > 0 && !(curr->res[0] == '\0' && curr->type == 'c'))
		{
			if (!(apply_prec(curr)))
				return (0);
		}
		if (curr->blank && !(curr->res[0] == '\0' && curr->type == 'c'))
		{
			if (!(apply_blank(curr)))
				return (0);
		}
		else
		{
			if (!(apply_zero(curr)))
				return (0);
		}
		curr = curr->next;
	}
	return (1);
}
