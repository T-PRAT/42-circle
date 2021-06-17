/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 15:15:38 by tprat             #+#    #+#             */
/*   Updated: 2021/06/17 18:24:41 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
