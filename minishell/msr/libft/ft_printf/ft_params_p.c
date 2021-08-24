/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:28:33 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/03/17 13:31:38 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*get_width(char *str, t_flag flags)
{
	int		i;
	int		j;
	char	*width;

	i = ft_strlen(str);
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
		width[j++] = ' ';
	return (width);
}

int	ft_print_p(va_list params, t_flag flags)
{
	char	*str;
	char	*first_str;
	char	*width;
	int		size;

	first_str = ft_uitox_lowercase(va_arg(params, uintptr_t));
	if (!first_str)
		return (-1);
	if (first_str[0] == '0' && flags.precision)
		first_str[0] = '\0';
	str = ft_strjoin("0x", first_str);
	width = get_width(str, flags);
	if (!width || !str)
		return (ft_free_all(3, width, str, first_str));
	if (!flags.minus)
		ft_putstr_fd(width, 1);
	ft_putstr_fd(str, 1);
	if (flags.minus)
		ft_putstr_fd(width, 1);
	size = ft_strlen(str) + ft_strlen(width);
	ft_free_all(3, width, first_str, str);
	return (size);
}
