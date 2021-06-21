/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 19:32:39 by tprat             #+#    #+#             */
/*   Updated: 2021/05/17 17:16:41by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc < 2)
		return (0);
	else
	{
		stack = fill_tab(argc, argv);
		check_tab(stack);
		if (!is_sorted(stack))
			select_sort(stack);
		if (stack->a)
			free(stack->a);
		if (stack->b)
			free(stack->b);
		if (stack->sorted)
			free(stack->sorted);
		free(stack);
	}
	return (0);
}
