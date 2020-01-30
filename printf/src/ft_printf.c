/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprat <tprat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/18 17:53:18 by tprat        #+#   ##    ##    #+#       */
/*   Updated: 2020/01/30 20:20:42 by tprat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int	fill_struct(char *al, t_arg *arg)
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
}

int	get_args(const char *al, va_list ap)
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
			if (!(arg->first = ft_strdup(first)))
				return (0);
			if (previous)
				ft_lstadd_back(&previous, arg);
			else
				previous = arg;
		}
	}
}

int	ft_printf(const char *al, ...)
{
	va_list	ap;
	char	*str;

	va_start(ap, al);
	str = va_arg(ap, char *);
	get_args(al, ap);
	va_end(ap);
	return (0);
}
