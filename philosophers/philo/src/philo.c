/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:43:22 by tprat             #+#    #+#             */
/*   Updated: 2021/06/24 20:42:08 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitor(t_params *params)
{
	int	i;

	while (42)
	{
		i = 0;
		while (i < params->n_philo)
		{
			if (get_timestamp(10) - params->philo[i].l_eat <= 0)
			{

				printf("%d philo %d died\n", get_timestamp(1000), \
				params->philo[i].num);
				return ;
			}
			if (params->philo[i].n_eat == 0)
				return ;
			i++;
		}
	}
}

void	*routine(void *arg)
{
	t_philo			*philo;

	philo = arg;
	while (philo->t_die > 0 && philo->n_eat != 0)
	{
		printf("%d philo %d is thinking\n", get_timestamp(1000), philo->num);
		pthread_mutex_lock(&philo->params->fork[philo->num]);
		printf("%d philo %d has taken a fork\n", get_timestamp(1000), philo->num);
		pthread_mutex_lock(&philo->params->fork[(philo->num + 1) % \
		philo->params->n_philo]);
		printf("%d philo %d has taken a fork\n", get_timestamp(1000), philo->num);
		printf("%d philo %d is eating\n", get_timestamp(1000), philo->num);
		usleep(philo->t_eat);
		philo->l_eat = get_timestamp(10);
		if (philo->n_eat != -1)
			philo->n_eat--;
		pthread_mutex_unlock(&philo->params->fork[philo->num]);
		pthread_mutex_unlock(&philo->params->fork[(philo->num + 1) % \
		philo->params->n_philo]);
		usleep(philo->t_sleep);
		printf("%d philo %d is sleeping\n", get_timestamp(1000), philo->num);
	}
	return (0);
}

void	init_philo(t_params *params)
{
	int	i;

	i = 0;
	params->philo = malloc(sizeof(t_philo) * params->n_philo);
	if (!params->philo)
		ft_error("malloc failed\n", params);
	params->fork = malloc(sizeof(pthread_mutex_t) * params->n_philo);
	if (!params->fork)
		ft_error("malloc failed\n", params);
	while (i < params->n_philo)
	{
		params->philo[i].num = i;
		params->philo[i].t_die = params->t_die;
		params->philo[i].t_eat = params->t_eat;
		params->philo[i].t_sleep = params->t_sleep;
		params->philo[i].n_eat = params->n_eat;
		params->philo[i].params = params;
		i++;
	}
}

void	start_philo(t_params *params)
{
	int				i;
	int				ret;

	ret = 0;
	init_philo(params);
	i = -1;
	while (++i < params->n_philo)
		pthread_mutex_init(&params->fork[i], NULL);
	i = -1;
	while (ret == 0 && ++i < params->n_philo)
	{
		ret = pthread_create(&params->philo[i].ptid, NULL, &routine, \
		&params->philo[i]);
		//UTILE ?
		usleep(100);
	}
	/*i = -1;
	while (++i < params->n_philo)
		pthread_join(params->philo[i].ptid, NULL);*/
	monitor(params);
	i = -1;
	while (++i < params->n_philo)
		pthread_mutex_destroy(&params->fork[i]);
}
