/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprat <tprat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/18 17:42:09 by tprat        #+#   ##    ##    #+#       */
/*   Updated: 2020/02/12 04:27:34 by tprat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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
	char			*flag;
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
