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

void	ft_error(t_stack *stack)
{
	if (stack->a)
		free(stack->a);
	if (stack->b)
		free(stack->b);
	free(stack);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	check_tab(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i <= stack->len_a)
	{
		j = 0;
		while (j <= stack->len_a)
		{
			if (i != j && stack->a[i] == stack->a[j])
				ft_error(stack);
			j++;
		}
		i++;
	}
}

t_stack	*fill_tab(int argc, char **argv)
{
	t_stack	*stack;

	argc--;
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (0);
	stack->a = malloc(sizeof(int) * (argc));
	stack->b = malloc(sizeof(int) * (argc));
	if (!stack->a || !stack->b)
		return (0);
	stack->max_l = argc;
	stack->len_a = argc;
	stack->len_b = 0;
	argc--;
	while (argc >= 0)
	{
		stack->a[argc] = ft_atoi(argv[argc + 1]);
		argc--;
	}
	return (stack);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	//printf("%s\n", argv[1]);
	if (argc < 3)
		return (0);
	else
	{
		stack = fill_tab(argc, argv);
		check_tab(stack);
		for (int i = 0; i < stack->len_a; i++)
			printf("a:%d\n", stack->a[i]);
		for (int i = 0; i < stack->len_b; i++)
			printf("b:%d\n", stack->b[i]);
		printf("_______________\n");
		rotate_a(stack);
		for (int i = 0; i < stack->len_a; i++)
			printf("a:%d\n", stack->a[i]);
		for (int i = 0; i < stack->len_b; i++)
			printf("b:%d\n", stack->b[i]);
	}
	return (0);
}
