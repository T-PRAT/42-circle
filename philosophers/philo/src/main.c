/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:15:37 by tprat             #+#    #+#             */
/*   Updated: 2021/08/11 15:15:42 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_params	*get_params(char **av, int ac, t_params *params)
{
	int	i;

	i = 0;
	params = malloc(sizeof(t_params));
	if (!params)
		ft_error("error : malloc failed\n", params);
	params->philo = NULL;
	params->fork = NULL;
	while (++i < ac)
		if (!is_num(av[i]))
			ft_error("error : an arg is not a positiv number\n", params);
	params->n_eat = -1;
	params->n_philo = ft_atoi(av[1], params);
	if (params->n_philo < 1)
		ft_error("error : must be at least 1 philosophers\n", params);
	params->t_die = ft_atoi(av[2], params);
	params->t_eat = ft_atoi(av[3], params);
	params->t_sleep = ft_atoi(av[4], params);
	if (ac == 6)
		params->n_eat = ft_atoi(av[5], params);
	return (params);
}

int	main(int ac, char **av)
{
	t_params	*params;

	params = NULL;
	if (ac != 5 && ac != 6)
		ft_error("error : incorrect number of arguments\n", params);
	else
	{
		params = get_params(av, ac, params);
		start_philo(params);
		if (params->philo)
			free(params->philo);
		if (params->fork)
			free(params->fork);
		free(params);
	}
}
