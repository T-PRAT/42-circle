/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:18:17 by rkowalsk          #+#    #+#             */
/*   Updated: 2020/11/25 14:25:52 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft.h"

typedef struct s_flag
{
	bool	error;
	bool	zero;
	bool	precision;
	bool	minus;
	bool	width;
	int		nb_width;
	int		nb_precisions;
	char	conv;
}	t_flag;

int				ft_printf(const char *str, ...);
char			*ft_uitox_lowercase(unsigned long n);
char			*ft_uitox_uppercase(unsigned long n);
int				ft_print_param(va_list params, t_flag flags);
int				ft_print_di(va_list params, t_flag flags);
int				ft_print_u(va_list params, t_flag flags);
int				ft_print_x_low(va_list params, t_flag flags);
int				ft_print_x_up(va_list params, t_flag flags);
int				ft_print_p(va_list params, t_flag flags);
int				ft_print_s(va_list params, t_flag flags);
t_flag			ft_pars_flags(va_list params, char *str);
int				ft_conv_or_flag(char c);
t_flag			ft_init_static(t_flag flags);
t_flag			ft_pars_cases(t_flag flags);
int				ft_free_all(const int number, ...);

#endif
