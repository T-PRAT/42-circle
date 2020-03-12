/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 01:20:55 by tprat             #+#    #+#             */
/*   Updated: 2020/03/12 01:42:34 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	apply_prec2(t_arg *curr)
{
	int		i;
	char	*tmp;

	i = 0;
	while (curr->res[i])
		i++;
	curr->prec -= i;
	while (curr->prec > 0 || (curr->prec == 0 && curr->res[0] == '-'))
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
		curr->prec--;
	}
	return (1);
}

int	apply_prec(t_arg *curr)
{
	if (ft_strchr("s", curr->type))
	{
		if (!(curr->res = ft_substr(curr->res, 0, curr->prec)))
			return (0);
	}
	else if (curr->prec > 0 && ft_strchr("diuxX", curr->type))
	{
		if (!(apply_prec2(curr)))
			return (0);
	}
	return (1);
}

int	apply_blank2(t_arg *curr, int i)
{
	char *tmp;

	curr->blank -= i;
	while (curr->blank > 0)
	{
		tmp = curr->res;
		if (!(curr->res = ft_strjoin(" ", curr->res)))
			return (0);
		free(tmp);
		curr->blank--;
	}
	return (1);
}

int	apply_blank(t_arg *curr)
{
	int		i;
	char	*tmp;

	i = 0;
	while (curr->res[i])
		i++;
	if (curr->blank < 0)
	{
		curr->blank += i;
		while (curr->blank < 0)
		{
			tmp = curr->res;
			if (!(curr->res = ft_strjoin(curr->res, " ")))
				return (0);
			free(tmp);
			curr->blank++;
		}
	}
	else
	{
		if (!(apply_blank2(curr, i)))
			return (0);
	}
	return (1);
}
