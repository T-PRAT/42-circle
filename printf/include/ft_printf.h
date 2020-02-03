/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprat <tprat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/18 17:42:09 by tprat        #+#   ##    ##    #+#       */
/*   Updated: 2020/02/03 18:23:04 by tprat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include "libft.h"
//a retirer
#include <stdio.h>

typedef struct 		s_arg
{
	char		*flag;
	char		type;
	struct s_arg	*first;
	struct s_arg	*next;
}			t_arg;

void	ft_lstaddarg_back(t_arg **alst, t_arg *new);
t_arg	*ft_lstnewarg(t_arg *first);

#endif
