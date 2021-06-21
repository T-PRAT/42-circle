/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 19:36:06 by tprat             #+#    #+#             */
/*   Updated: 2021/06/21 18:52:59 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	*sorted;
	int	len_a;
	int	len_b;
	int	max_l;
}				t_stack;

t_stack	*fill_tab(int argc, char **argv);
int		is_sorted(t_stack *stack);
void	check_tab(t_stack *stack);
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
int		no_neg(int nbr);
void	sort_push(t_stack *stack);
void	move_top(int nbr, t_stack *stack);

#endif
