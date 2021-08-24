/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params_uxx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:28:33 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/03/17 13:48:00 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*get_precision(char *str, t_flag flags)
{
	int		i;
	int		j;
	char	*prec;

	i = ft_strlen(str);
	if (!flags.precision || flags.nb_precisions <= i)
		i = 0;
	else
		i = flags.nb_precisions - i;
	prec = malloc(sizeof(char) * (i + 1));
	if (!prec)
		return (NULL);
	prec[i] = '\0';
	j = 0;
	while (j < i)
		prec[j++] = '0';
	return (prec);
}

static char	*get_width(char *str, char *prec, t_flag flags)
{
	int		i;
	int		j;
	char	*width;
	char	c;

	c = ' ';
	if (flags.zero)
		c = '0';
	i = ft_strlen(str) + ft_strlen(prec);
	if (flags.nb_width <= i)
		i = 0;
	else
		i = flags.nb_width - i;
	width = malloc(sizeof(char) * (i + 1));
	if (!width)
		return (NULL);
	width[i] = '\0';
	j = 0;
	while (j < i)
		width[j++] = c;
	return (width);
}

int	ft_print_u(va_list params, t_flag flags)
{
	char	*str;
	char	*prec;
	char	*width;
	int		size;

	str = ft_uitoa(va_arg(params, unsigned int));
	if (!str)
		return (-1);
	if (ft_atoi(str) == 0 && flags.precision)
		str[0] = '\0';
	prec = get_precision(str, flags);
	width = get_width(str, prec, flags);
	if (!width || !prec)
		return (ft_free_all(3, width, str, prec));
	if (!flags.minus)
		ft_putstr_fd(width, 1);
	ft_putstr_fd(prec, 1);
	ft_putstr_fd(str, 1);
	if (flags.minus)
		ft_putstr_fd(width, 1);
	size = ft_strlen(str) + ft_strlen(prec) + ft_strlen(width);
	ft_free_all(3, str, width, prec);
	return (size);
}

int	ft_print_x_low(va_list params, t_flag flags)
{
	char	*str;
	char	*prec;
	char	*width;
	int		size;

	str = ft_uitox_lowercase(va_arg(params, unsigned int));
	if (!str)
		return (-1);
	if (str[0] == '0' && flags.precision && !flags.nb_precisions)
		str[0] = '\0';
	prec = get_precision(str, flags);
	width = get_width(str, prec, flags);
	if (!prec || !width)
		return (ft_free_all(3, width, str, prec));
	if (!flags.minus)
		ft_putstr_fd(width, 1);
	ft_putstr_fd(prec, 1);
	ft_putstr_fd(str, 1);
	if (flags.minus)
		ft_putstr_fd(width, 1);
	size = ft_strlen(str) + ft_strlen(prec) + ft_strlen(width);
	ft_free_all(3, str, width, prec);
	return (size);
}

int	ft_print_x_up(va_list params, t_flag flags)
{
	char	*str;
	char	*prec;
	char	*width;
	int		size;

	str = ft_uitox_uppercase(va_arg(params, unsigned int));
	if (!str)
		return (-1);
	if (str[0] == '0' && flags.precision && !flags.nb_precisions)
		str[0] = '\0';
	prec = get_precision(str, flags);
	width = get_width(str, prec, flags);
	if (!prec || !width)
		return (ft_free_all(3, width, str, prec));
	if (!flags.minus)
		ft_putstr_fd(width, 1);
	ft_putstr_fd(prec, 1);
	ft_putstr_fd(str, 1);
	if (flags.minus)
		ft_putstr_fd(width, 1);
	size = ft_strlen(str) + ft_strlen(prec) + ft_strlen(width);
	ft_free_all(3, str, width, prec);
	return (size);
}
