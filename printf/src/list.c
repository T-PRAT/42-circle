/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 22:30:15 by tprat             #+#    #+#             */
/*   Updated: 2020/02/24 19:02:13 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*fill_res(t_arg *arg, va_list ap)
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

int		fill_flags(const char *al, t_arg *arg, va_list ap)
{
	int i;

	i = 0;
	if (al[i] == '0')
		(al[++i] == '*') ? (arg->zero = va_arg(ap, int)) :
		(arg->zero = ft_atoi(al + i));
	else if (ft_isdigit(al[i]) || al[i] == '-')
		arg->blank = ft_atoi(al + i);
	else if (al[i] == '*')
		arg->blank = va_arg(ap, int);
	while (ft_isdigit(al[i]) || al[i] == '*' || al[i] == '-')
		i++;
	if (al[i] == '.')
		(al[++i] == '*') ? (arg->prec = va_arg(ap, int)) :
		(arg->prec = ft_atoi(al + i));
	while (ft_isdigit(al[i]) || al[i] == '.' || al[i] == '-')
		i++;
	if (ft_strchr("cspdiuxX%", al[i]))
		arg->type = al[i];
	return (1);
}

t_arg	*new_elem(const char *al, va_list ap)
{
	t_arg *new;

	if (!(new = (t_arg *)malloc(sizeof(t_arg))))
		return (0);
	new->zero = 0;
	new->prec = 0;
	new->blank = 0;
	if (!(fill_flags(al, new, ap)))
		return (0);
	if (!(new->next = malloc(sizeof(t_arg))))
		return (0);
	new->next = 0;
	if (!(new->first = malloc(sizeof(t_arg))))
		return (0);
	new->first = 0;
	if (!(new->res = fill_res(new, ap)))
		return (0);
	return (new);
}

t_arg	*create_list(const char *al, va_list ap)
{
	int		i;
	t_arg	*curr;
	t_arg	*first;
	t_arg	*prev;

	first = 0;
	prev = 0;
	i = 0;
	while (al[i])
	{
		if (al[i] == '%')
		{
			i++;
			if (!(curr = new_elem(al + i, ap)))
				return (0);
			(first) ? (curr->first = first) :
			(first = curr);
			if (prev)
				prev->next = curr;
			prev = curr;
		}
		else
			i++;
	}
	return (first);
}
