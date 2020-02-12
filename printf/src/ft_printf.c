/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprat <tprat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/18 17:53:18 by tprat        #+#   ##    ##    #+#       */
/*   Updated: 2020/02/12 04:26:56 by tprat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *al, ...)
{
	t_arg	*arg;
	va_list	ap;

	va_start(ap, al);
	if (!(arg = get_flags(al)))
		return (0);
	if (!(get_args(ap, arg)))
		return (0);
	while (arg)
	{
		printf("flag:%s\n", arg->flag);
		printf("type:%c\n", arg->type);
		printf("res:%s\n", arg->res);
		arg = arg->next;
	}
	va_end(ap);
	return (0);
}
