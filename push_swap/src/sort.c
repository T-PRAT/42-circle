/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 12:42:56 by tprat             #+#    #+#             */
/*   Updated: 2021/06/18 18:46:12 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_stack *stack)
{
	if (stack->a[0] > stack->a[1] && stack->a[1] > stack->a[2])
	{
		swap_a(stack);
		rrotate_a(stack);
	}
	else if (stack->a[0] < stack->a[1] && stack->a[0] > stack->a[2])
		rrotate_a(stack);
	else if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2])
	{
		swap_a(stack);
		rotate_a(stack);
	}
	else if (stack->a[0] > stack->a[1] && stack->a[0] < stack->a[2])
		swap_a(stack);
	else if (stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2])
		rotate_a(stack);
}

//TODO
void	sort_five(t_stack *stack)
{
	push_b(stack);
	push_b(stack);
	sort_three(stack);
}

void	sort_medium(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		printf("i:%d\n", i);
		j = stack->max_l / 4;
		while (j > 0)
		{
			nbr_to_push(stack->sorted[(stack->max_l - 1) / 4 * i], \
			stack->sorted[(stack->max_l - 1) / 4 * (i + 1)], stack);
			push_b(stack);
			j--;
		}
		i++;
	}
}

void	select_sort(t_stack *stack)
{
	if (stack->len_a == 2)
	{
		if (stack->a[0] > stack->a[1])
			swap_a(stack);
	}
	else if (stack->len_a == 3)
		sort_three(stack);
	else if (stack->len_a == 5)
		sort_five(stack);
	else if (stack->len_a < 100)
		sort_medium(stack);
	//else if (stack->len_a >= 100)
		//sort_big(stack);
}
