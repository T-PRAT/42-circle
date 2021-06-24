/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:42:19 by tprat             #+#    #+#             */
/*   Updated: 2021/06/10 11:19:59by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_params	*get_params(char **av, int ac, t_params *params)
{
	int	i;

	i = 1;
	params = malloc(sizeof(t_params));
	if (!params)
		ft_error("malloc failed\n", params);
	params->philo = NULL;
	params->fork = NULL;
	while (i < ac)
	{
		if (!is_num(av[i]))
			ft_error("an arg is not a number\n", params);
		i++;
	}
	params->n_eat = -1;
	params->n_philo = ft_atoi(av[1]);
	params->t_die = ft_atoi(av[2]);
	params->t_eat = ft_atoi(av[3]);
	params->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
		params->n_eat = ft_atoi(av[5]);
	return (params);
}

int	main(int ac, char **av)
{
	t_params	*params;

	params = NULL;
	if (ac != 5 && ac != 6)
		ft_error("incorrect number of arguments\n", params);
	else
	{
		params = get_params(av, ac, params);
		start_philos(params);
		if (params->philo)
			free(params->philo);
		if (params->fork)
			free(params->fork);
		free(params);
	}
}
