/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprat <tprat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/18 17:42:09 by tprat        #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 20:31:28 by tprat       ###    #+. /#+    ###.fr     */
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
	char		*flag;
	char		type;
	struct s_arg	*first;
	struct s_arg	*next;
}			t_arg;

int		fill_struct(const char *al, t_arg *arg);
t_arg	*new_elem(const char *al);
t_arg	*get_args(const char *al);

#endif
