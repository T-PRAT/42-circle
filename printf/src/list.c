/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 22:30:15 by tprat             #+#    #+#             */
/*   Updated: 2020/03/13 00:12:59 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*chardup(int val)
{
	char *res;

	if (!(res = malloc(sizeof(char) * 2)))
		return (0);
	res[0] = val;
	res[1] = 0;
	return (res);
}

char	*iadress(unsigned long long val)
{
	char *res;
	char *tmp;

	res = ft_itoa_base(val, "0123456789abcdef");
	tmp = res;
	res = ft_strjoin("0x", res);
	free(tmp);
	return (res);
}

char	*fill_res(t_arg *arg, va_list ap)
{
	char *res;

	res = 0;
	if (arg->type == 'c')
		res = chardup(va_arg(ap, int));
	if (arg->type == 's')
	{
		(arg->prec == -1 && !(arg->blank)) ? (res = ft_strdup("")) :
		(res = ft_strdup_null(va_arg(ap, char *)));
	}
	if (arg->type == 'd' || arg->type == 'i')
		res = ft_itoa(va_arg(ap, int));
	if (arg->type == 'u')
		res = ft_utoa(va_arg(ap, unsigned int));
	if (arg->type == 'x')
		res = ft_itoa_base(va_arg(ap, unsigned int), "0123456789abcdef");
	if (arg->type == 'X')
		res = ft_itoa_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
	if (arg->type == 'p')
		res = iadress(va_arg(ap, unsigned long long));
	if (arg->type == '%')
		res = ft_strdup("%");
	return (res);
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
	new->next = 0;
	if (!(new->res = fill_res(new, ap)))
		return (0);
	return (new);
}

t_arg	*create_list(const char *al, va_list ap, t_arg *first)
{
	int		i;
	t_arg	*curr;
	t_arg	*prev;

	prev = 0;
	i = 0;
	while (al[i++])
	{
		if (al[i - 1] == '%')
		{
			if (!(curr = new_elem(al + i, ap)))
				return (0);
			if (!(first))
				first = curr;
			if (prev)
				prev->next = curr;
			prev = curr;
			if (curr->type == '%')
			{
				while (al[i++] != '%')
					curr->type = '%';
			}
		}
	}
	return (first);
}
