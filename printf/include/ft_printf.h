/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 23:23:32 by tprat             #+#    #+#             */
/*   Updated: 2020/03/12 23:33:52 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct		s_arg
{
	int				blank;
	int				zero;
	int				prec;
	char			type;
	char			*res;
	struct s_arg	*next;
}					t_arg;

int					ft_printf(const char *al, ...);
t_arg				*create_list(const char *al, va_list ap, t_arg *first);
int					apply_flags(t_arg *curr);
int					print_all(const char *al, t_arg *current);
int					free_list(t_arg *current);
int					fill_flags(const char *al, t_arg *arg, va_list ap);
int					apply_blank(t_arg *curr);
int					apply_prec(t_arg *curr);

#endif
