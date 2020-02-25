/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 23:23:32 by tprat             #+#    #+#             */
/*   Updated: 2020/02/25 18:46:53 by tprat            ###   ########lyon.fr   */
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

int		ft_printf(const char *al, ...);
t_arg	*create_list(const char *al, va_list ap);
int		apply_flags(t_arg *current);
int		print_all(const char *al, t_arg *current);
void	free_all(t_arg *current);

#endif
