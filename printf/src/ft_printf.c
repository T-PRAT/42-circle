/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprat <tprat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/18 17:53:18 by tprat        #+#   ##    ##    #+#       */
/*   Updated: 2020/02/05 20:11:54 by tprat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		fill_struct(const char *al, t_arg *arg)
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
	else
		arg->flag = 0;
	if (ft_strchr("cspdiuxX%", al[i]))
		arg->type = al[i];
	return (1);
}

t_arg	*get_args(const char *al)
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
			i++;
			if (!(arg = ft_lstnewarg(first)))
				return (0);
			if (!(fill_struct(al + i, arg)))
				return (0);
			if (previous)
				ft_lstaddarg_back(&previous, arg);
			else
				previous = arg;
		}
		i++;
	}
		printf("flag:%s\n", first->flag);
		printf("type:%c\n", first->type);
	return (first);
}

int		ft_printf(const char *al, ...)
{
	va_list	ap;
	char	*str;
	t_arg	*arg;

	va_start(ap, al);
	str = va_arg(ap, char *);
	if (!(arg = get_args(al)))
		return (0);
	while (arg)
	{
		printf("flag:%s\n", arg->flag);
		printf("type:%c\n", arg->type);
		arg = arg->next;
	}
	va_end(ap);
	return (0);
}
