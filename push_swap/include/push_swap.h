/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 19:36:06 by tprat             #+#    #+#             */
/*   Updated: 2021/06/09 13:45:16 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
# include "../libft/libft.h"

# include <stdio.h>
typedef struct	s_stack
{
	int	*a;
	int	*b;
	int	len_a;
	int	len_b;
	int	max_l;
}				t_stack;

#endif
