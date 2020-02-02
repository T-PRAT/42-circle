/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprat <tprat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/18 17:53:18 by tprat        #+#   ##    ##    #+#       */
/*   Updated: 2020/02/03 00:36:18 by tprat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int	fill_struct(const char *al, t_arg *arg)
{
	int i;

	i = 0;
	while ((ft_strchr("-0.*", al[i])))
		i++;
	if (i)
	{
		if (!(arg->flag = ft_substr(al, 0, i)))
			return (0);
	}
	if (ft_strchr("cspdiuxX%", al[++i]))
		arg->type = al[i];
	return (1);
}

int	get_args(const char *al)
{
	int		i;
	t_arg	*arg;
	t_arg	*first;
	t_arg	*previous;

	first = 0;
	previous = 0;
	i = 0;
	while (al[i])
	{
		if (al[i] == '%')
		{
			if (!(arg = malloc(sizeof(t_arg))))
				return (0);
			if (!(fill_struct(al + i, arg)))
				return (0);
			if (!(first))
				first = arg;
			if (!(arg->first = first))
				return (0);
			if (previous)
				ft_lstaddarg_back(&previous, arg);
			else
				previous = arg;
			i++;
		}
	}
	return (1);
}

int	ft_printf(const char *al, ...)
{
	va_list	ap;
	char	*str;

	va_start(ap, al);
	str = va_arg(ap, char *);
	get_args(al);
	va_end(ap);
	return (0);
}
