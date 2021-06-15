/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:12:26 by tprat             #+#    #+#             */
/*   Updated: 2021/06/15 18:21:16 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_a(t_stack *stack)
{
	int	tmp;

	if (stack->len_a >= 2)
	{
		tmp = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = tmp;
	}
	ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_stack *stack)
{
	int	tmp;

	if (stack->len_b >= 2)
	{
		tmp = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = tmp;
	}
	ft_putstr_fd("sb\n", 1);
}

void	swap_all(t_stack *stack)
{
	int	tmp;

	if (stack->len_a >= 2)
	{
		tmp = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = tmp;
	}
	if (stack->len_b >= 2)
	{
		tmp = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = tmp;
	}
	ft_putstr_fd("ss\n", 1);
}

void	push_a(t_stack *stack)
{
	int	i;

	i = stack->len_a;
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = stack->b[0];
	i = 0;
	while (i < stack->len_b - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->len_a++;
	stack->len_b--;
	ft_putstr_fd("pa\n", 1);
}

void	push_b(t_stack *stack)
{
	int	i;

	i = stack->len_b;
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = stack->a[0];
	i = 0;
	while (i < stack->len_a - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->len_b++;
	stack->len_a--;
	ft_putstr_fd("pb\n", 1);
}
