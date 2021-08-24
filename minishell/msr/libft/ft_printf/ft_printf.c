/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:33:52 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/03/17 15:46:05 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	patch_norme(va_list params, const char *str, size_t i)
{
	t_flag	flags;

	flags = ft_pars_flags(params, (char *)str + i);
	if (flags.error)
		return (-1);
	return (ft_print_param(params, flags));
}

static int	printing(va_list params, const char *str, size_t i)
{
	int		size;
	int		ret;

	size = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			ret = patch_norme(params, str, ++i);
			if (ret == -1)
				return (-1);
			size += ret;
			while (ft_conv_or_flag(str[i]) != 1)
				i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			size++;
		}
		i++;
	}
	return (size);
}

int	ft_printf(const char *str, ...)
{
	va_list	params;
	int		size;
	size_t	i;

	i = 0;
	va_start(params, str);
	size = printing(params, str, i);
	va_end(params);
	return (size);
}
