/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 19:36:06 by tprat             #+#    #+#             */
/*   Updated: 2021/06/18 13:32:17 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "../libft/libft.h"

# include <stdio.h>
typedef struct s_stack
{
	int	*a;
	int	*b;
	int	*sorted;
	int	len_a;
	int	len_b;
	int	max_l;
}				t_stack;

void	sorted_tab(t_stack *stack);
void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	swap_all(t_stack *stack);
void	push_a(t_stack *stack);
void	push_b(t_stack *stack);
void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	rotate_all(t_stack *stack);
void	rrotate_a(t_stack *stack);
void	rrotate_b(t_stack *stack);
void	rrotate_all(t_stack *stack);
void	select_sort(t_stack *stack);
int		nbr_in_range(int min, int max, int *stack, int stack_size);
void	nbr_to_push(int min, int max, t_stack *stack);

#endif
