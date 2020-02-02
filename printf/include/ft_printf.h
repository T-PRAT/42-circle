/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprat <tprat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/18 17:42:09 by tprat        #+#   ##    ##    #+#       */
/*   Updated: 2020/02/02 22:53:43 by tprat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include "libft.h"

typedef struct 		s_arg
{
	char		*flag;
	char		type;
	struct s_arg	*first;
	struct s_arg	*next;
}			t_arg;

void	ft_lstaddarg_back(t_arg **alst, t_arg *new);

#endif
