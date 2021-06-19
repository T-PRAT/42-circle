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

void	sort_push(t_stack *stack)
{

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
	printf("min:%d||max:%d\n", min, max);
	j = stack->len_a - 1;
	while (!(stack->a[i] >= min && stack->a[i] <= max) && i < stack->len_a - 1)
		i++;
	while (!(stack->a[j] >= min && stack->a[j] <= max) && j > 0)
		j--;
	printf("i:%d||j:%d\n", i, (stack->len_a - 1) - j);
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

int	nbr_in_range(int min, int max, int *stack, int stack_size)
{
	stack_size--;
	while (stack_size > 0)
	{
		if (stack[stack_size] < min || stack[stack_size] > max)
			return (1);
		stack_size--;
	}
	return (0);
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
