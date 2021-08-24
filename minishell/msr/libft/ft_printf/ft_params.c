/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:57:04 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/03/17 12:42:43 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_c(va_list params, t_flag flags)
{
	int	i;

	i = 0;
	if (flags.width || flags.minus)
	{
		if (flags.minus)
			ft_putchar_fd(va_arg(params, int), 1);
		while (i < flags.nb_width - 1)
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
		if (!flags.minus)
			ft_putchar_fd(va_arg(params, int), 1);
	}
	else
		ft_putchar_fd(va_arg(params, int), 1);
	return (1 + i);
}

int	ft_print_percent(t_flag flags)
{
	int		i;
	char	c;

	c = ' ';
	if (flags.zero)
		c = '0';
	i = 0;
	if (flags.width || flags.minus)
	{
		if (flags.minus)
			ft_putchar_fd('%', 1);
		while (i < flags.nb_width - 1)
		{
			ft_putchar_fd(c, 1);
			i++;
		}
		if (!flags.minus)
			ft_putchar_fd('%', 1);
	}
	else
		ft_putchar_fd('%', 1);
	return (1 + i);
}

int	ft_print_param(va_list params, t_flag flags)
{
	if (flags.conv == 'c')
		return (ft_print_c(params, flags));
	else if (flags.conv == 's')
		return (ft_print_s(params, flags));
	else if (flags.conv == 'd' || flags.conv == 'i')
		return (ft_print_di(params, flags));
	else if (flags.conv == 'u')
		return (ft_print_u(params, flags));
	else if (flags.conv == 'x')
		return (ft_print_x_low(params, flags));
	else if (flags.conv == 'X')
		return (ft_print_x_up(params, flags));
	else if (flags.conv == 'p')
		return (ft_print_p(params, flags));
	else if (flags.conv == '%')
		return (ft_print_percent(flags));
	return (-1);
}
