/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 15:15:38 by tprat             #+#    #+#             */
/*   Updated: 2021/06/18 12:46:59by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	move_top(int nbr, t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = stack->len_b - 1;
	while (stack->b[i] != nbr && i < stack->len_b - 1)
		i++;
	while (stack->b[j] != nbr && j > 0)
		j--;
	if (i <= ((stack->len_b - 1) - j))
	{
		while (i > 0)
		{
			rotate_b(stack);
			i--;
		}
	}
	else
	{
		while (j <= (stack->len_b - 1))
		{
			rrotate_b(stack);
			j++;
		}
	}
}

void	sort_push(t_stack *stack)
{
	int	i;

	i = stack->len_b - 1;
	while (i >= 0)
	{
		move_top(stack->sorted[i], stack);
		push_a(stack);
		i--;
	}
}

int	no_neg(int nbr)
{
	if (nbr < 0)
		return (0);
	else
		return (nbr);
}

void	nbr_to_push(int min, int max, t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = stack->len_a - 1;
	while (!(stack->a[i] >= min && stack->a[i] <= max) && i < stack->len_a - 1)
		i++;
	while (!(stack->a[j] >= min && stack->a[j] <= max) && j > 0)
		j--;
	if (i <= ((stack->len_a - 1) - j))
	{
		while (i > 0)
		{
			rotate_a(stack);
			i--;
		}
	}
	else
	{
		while (j <= (stack->len_a - 1))
		{
			rrotate_a(stack);
			j++;
		}
	}
}

void	sorted_tab(t_stack *stack)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < stack->max_l)
	{
		j = 0;
		while (j < stack->max_l - 1)
		{
			if (stack->sorted[j] > stack->sorted[j + 1])
			{
				tmp = stack->sorted[j];
				stack->sorted[j] = stack->sorted[j + 1];
				stack->sorted[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
