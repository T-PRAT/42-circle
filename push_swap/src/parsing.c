/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:09:07 by tprat             #+#    #+#             */
/*   Updated: 2021/06/21 18:49:35 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error(t_stack *stack)
{
	if (stack->a)
		free(stack->a);
	if (stack->b)
		free(stack->b);
	if (stack->sorted)
		free(stack->sorted);
	free(stack);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->len_a - 1)
	{
		if (stack->a[i] > stack->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	if (str[i] == 0)
		return (0);
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_strchr("0123456789", str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_tab(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->len_a)
	{
		j = 0;
		while (j < stack->len_a)
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
	long	nbr;

	argc--;
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (0);
	stack->a = malloc(sizeof(int) * (argc));
	stack->b = malloc(sizeof(int) * (argc));
	stack->sorted = malloc(sizeof(int) * (argc));
	if (!stack->a || !stack->b || !stack->sorted)
		return (0);
	stack->max_l = argc;
	stack->len_a = argc;
	stack->len_b = 0;
	while (--argc >= 0)
	{
		nbr = ft_atoi(argv[argc + 1]);
		if (nbr > INT32_MAX || nbr < INT32_MIN || !ft_isnum(argv[argc + 1]))
			ft_error(stack);
		stack->a[argc] = (int)nbr;
		stack->sorted[argc] = (int)nbr;
	}
	sorted_tab(stack);
	return (stack);
}
