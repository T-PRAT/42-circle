/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprat <tprat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/18 17:53:18 by tprat        #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 20:10:52 by tprat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

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
