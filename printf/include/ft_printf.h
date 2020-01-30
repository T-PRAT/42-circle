/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprat <tprat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/18 17:42:09 by tprat        #+#   ##    ##    #+#       */
/*   Updated: 2020/01/30 19:36:34 by tprat       ###    #+. /#+    ###.fr     */
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

int		ft_printf(const char *al, ...);
void	ft_putstr(char *s);
void	ft_putchar(char c);
void	ft_putnbr(int n);
#endif
