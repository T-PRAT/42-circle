/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 22:30:15 by tprat             #+#    #+#             */
/*   Updated: 2020/02/26 16:02:06 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	apply_prec(t_arg *current)
{
	int 	i;
	char	*tmp;

	i = -1;
	if (ft_strchr("s", current->type))
	{
		if (!(current->res = ft_substr(current->res, 0, current->prec)))
			return (0);
	}
	else if (current->prec > 0 && ft_strchr("diuxX", current->type))
	{
		while (current->res[++i]);
		current->prec -= i;
		while (current->prec > 0)
		{
			tmp = current->res;
			if (!(current->res = ft_strjoin("0", current->res)))
				return (0);
			free(tmp);
			current->prec--;
		}
	}
	return (1);
}

int	apply_blank(t_arg *current)
{
	int i;
	char	*tmp;

	i = -1;
	while (current->res[++i]);
	if (current->blank < 0)
	{
		current->blank += i;
		while (current->blank < 0)
		{
			tmp = current->res;
			if (!(current->res = ft_strjoin(current->res, " ")))
				return (0);
			free(tmp);
			current->blank++;
		}
	}
	else
	{
		current->blank -= i;
		while (current->blank > 0)
		{
			tmp = current->res;
			if (!(current->res = ft_strjoin(" ", current->res)))
				return (0);
			free(tmp);
			current->blank--;
		}
	}

	return (1);
}

int	apply_zero(t_arg *current)
{
	int i;
	char	*tmp;

	i = -1;
	while (current->res[++i]);
	current->zero -= i;
	while (current->zero > 0)
	{
		tmp = current->res;
		if (!(current->res = ft_strjoin("0", current->res)))
			return (0);
		free(tmp);
		current->zero--;
	}
	return (1);
}

int	apply_flags(t_arg *current)
{
	while (current)
	{
		if (current->prec)
		{
			if (!(apply_prec(current)))
				return (0);
		}
		if (current->blank)
		{
			if (!(apply_blank(current)))
				return (0);
		}
		else
			if (!(apply_zero(current)))
				return (0);
		current = current->next;
	}
	return (1);
}
