/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:43:22 by tprat             #+#    #+#             */
/*   Updated: 2021/06/10 13:17:13 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_params	*params;

	params = arg;
	printf("hello\n");
	return (0);
}

void	start_philos(t_params *params)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	params->ptid = malloc(sizeof(pthread_t) * params->n_philo);
	if (!params->ptid)
		ft_error("malloc failed\n", params);
	while (ret == 0 && i < params->n_philo)
	{
		ret = pthread_create(&params->ptid[i], NULL, &routine, params);
		i++;
	}
	i = 0;
	while (i < params->n_philo)
	{
		pthread_join(params->ptid[i], NULL);
		i++;
	}
}
