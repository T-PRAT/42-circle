/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 23:23:32 by tprat             #+#    #+#             */
/*   Updated: 2020/02/13 04:03:12 by tprat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include "../libft/libft.h"
//a retirer
#include <stdio.h>

typedef struct 		s_arg
{
	int				blank;
	int				zero;
	int				prec;
	char			type;
	char			*res;
	struct s_arg	*first;
	struct s_arg	*next;
}			t_arg;

int		fill_struct(const char *al, t_arg *arg);
t_arg	*new_elem(const char *al);
t_arg	*get_flags(const char *al);
int		get_args(va_list ap, t_arg *arg);

#endif
