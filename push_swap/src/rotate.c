/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 13:08:00 by tprat             #+#    #+#             */
/*   Updated: 2021/06/11 13:18:43 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_a(t_stack *stack)
{
	int	i;
	int	first;

	i = 0;
	first = stack->a[0];
	while (i < stack->len_a - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[i] = first;
	ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_stack *stack)
{
	int	i;
	int	first;

	i = 0;
	first = stack->b[0];
	while (i < stack->len_b - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[i] = first;
	ft_putstr_fd("rb\n", 1);
}

void	rotate_all(t_stack *stack)
{
	int	i;
	int	first;

	i = 0;
	first = stack->a[0];
	while (i < stack->len_a - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[i] = first;
	i = 0;
	first = stack->b[0];
	while (i < stack->len_b - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[i] = first;
	ft_putstr_fd("rr\n", 1);
}
