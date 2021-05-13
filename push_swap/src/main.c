/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 19:32:39 by tprat             #+#    #+#             */
/*   Updated: 2021/05/13 20:37:10 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	fill_tab(int argc, char **argv)
{
	t_stack *stack;

	argc -= 2;
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (0);
	stack->a = malloc(sizeof(int) * (argc) + 1);
	stack->b = malloc(sizeof(int) * (argc) + 1);
	if (!stack->a || !stack->b)
		return (0);
	stack->a[argc] = 0;
	stack->b[argc] = 0;
	argc--;
	while (argc >= 0)
	{
		stack->a[argc] = ft_atoi(argv[argc -2]);
		argc--;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc < 3)
		return (0);
	else
		fill_tab(argc, argv);
	return (0);
}
