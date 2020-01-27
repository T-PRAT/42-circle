/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/18 17:53:18 by tprat        #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 18:46:40 by tprat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_arg(const char *al, va_list ap)
{
	int i;

	i = 0;
	while (al[i])
	{
		if (al[i] == '%')
		{
			while((ft_strchr("-0.*", al[i])))
		}
	}
}

int	ft_printf(const char *al, ...)
{
	va_list	ap;
	char	*str;

	va_start(ap, al);
	str = va_arg(ap, char *);
	get_arg(al, ap);
	va_end(ap);
	return(0);
}
