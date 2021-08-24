/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:13:20 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/03/17 14:15:59 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static t_flag	star(va_list params, t_flag flags, int *i)
{
	if (flags.width == true)
	{
		flags.error = true;
		return (flags);
	}
	flags.nb_width = va_arg(params, int);
	if (flags.nb_width < 0)
	{
		flags.minus = true;
		flags.nb_width = -flags.nb_width;
	}
	flags.width = true;
	*i += 1;
	return (flags);
}

static t_flag	dot(va_list params, char *str, t_flag flags, int *i)
{
	if (flags.precision == true)
	{
		flags.error = true;
		return (flags);
	}
	flags.precision = true;
	if (str[++*i] == '*')
	{
		flags.nb_precisions = va_arg(params, int);
		if (flags.nb_precisions < 0)
			flags.precision = false;
		*i += 1;
	}
	else
	{
		if (str[*i] == '-')
		{
			flags.error = true;
			return (flags);
		}
		flags.nb_precisions = ft_atoi(str + *i);
		while (ft_isdigit(str[*i]))
			*i += 1;
	}
	return (flags);
}

static t_flag	zero_minus_error(int ret, char *str, t_flag flags, int *i)
{
	if (ret == 0)
	{
		flags.error = true;
		return (flags);
	}
	else if (str[*i] == '-')
	{
		flags.minus = true;
		*i += 1;
	}
	else if (str[*i] == '0')
	{
		flags.zero = true;
		*i = *i + 1;
	}
	return (flags);
}

static t_flag	star_digit_dot(va_list params, char *str, t_flag flags, int *i)
{
	if (str[*i] == '*')
	{
		flags = star(params, flags, i);
		if (flags.error)
			return (flags);
	}
	else if (ft_isdigit(str[*i]))
	{
		if (flags.width == true)
		{
			flags.error = true;
			return (flags);
		}
		flags.width = true;
		flags.nb_width = ft_atoi(str + *i);
		while (ft_isdigit(str[*i]))
			*i += 1;
	}
	else if (str[*i] == '.')
	{
		flags = dot(params, str, flags, i);
		if (flags.error)
			return (flags);
	}
	return (flags);
}

t_flag	ft_pars_flags(va_list params, char *str)
{
	static t_flag	flags;
	int				ret;
	int				i;

	flags = ft_init_static(flags);
	i = 0;
	ret = ft_conv_or_flag(str[i]);
	while (str[i] && (ret != 1))
	{
		ret = ft_conv_or_flag(str[i]);
		if (ret == 0 || str[i] == '-' || str[i] == '0')
			flags = zero_minus_error(ret, str, flags, &i);
		else if (str[i] == '*' || ft_isdigit(str[i]) || str[i] == '.')
			flags = star_digit_dot(params, str, flags, &i);
		if (flags.error)
			return (flags);
	}
	flags.conv = str[i];
	flags = ft_pars_cases(flags);
	return (flags);
}
