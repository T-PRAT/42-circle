/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 13:24:04 by tprat             #+#    #+#             */
/*   Updated: 2021/06/11 13:54:23 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rrotate_a(t_stack *stack)
{
	int	i;
	int	last;

	i = stack->len_a;
	last = stack->a[stack->len_a - 1];
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = last;
	ft_putstr_fd("rra\n", 1);
}

void	rrotate_b(t_stack *stack)
{
	int	i;
	int	last;

	i = stack->len_b;
	last = stack->b[stack->len_b - 1];
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = last;
	ft_putstr_fd("rrb\n", 1);
}

void	rrotate_all(t_stack *stack)
{
	int	i;
	int	last;

	i = stack->len_a;
	last = stack->a[stack->len_a - 1];
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = last;
	i = stack->len_b;
	last = stack->b[stack->len_b - 1];
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = last;
	ft_putstr_fd("rrr\n", 1);
}
