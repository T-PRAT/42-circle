/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:43:22 by tprat             #+#    #+#             */
/*   Updated: 2021/06/22 17:09:34 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	switch_fork(int	num, t_params *params, int bool)
{
	if (num == params->n_philo - 1)
		params->fork[0] = bool;
	else
		params->fork[num] = bool;
	if (num == 0)
		params->fork[params->n_philo] = bool;
	else
		params->fork[num - 1] = bool;
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	pthread_mutex_lock(&philo->params->mutex);
	switch_fork(philo->num, philo->params, 0);
	usleep(philo->t_eat);
	printf("philo %d is eating\n", philo->num);
	pthread_mutex_unlock(&philo->params->mutex);
	return (0);
}

void	init_philo(t_params *params)
{
	int	i;

	i = 0;
	params->philo = malloc(sizeof(t_philo) * params->n_philo);
	if (!params->philo)
		ft_error("malloc failed\n", params);
	params->fork = malloc(sizeof(char) * params->n_philo);
	if (!params->fork)
		ft_error("malloc failed\n", params);
	memset(params->fork, 1, params->n_philo);
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

void	start_philos(t_params *params)
{
	int				i;
	int				ret;

	i = 0;
	ret = 0;
	init_philo(params);
	pthread_mutex_init(&params->mutex, NULL);
	while (ret == 0 && i < params->n_philo)
	{
		ret = pthread_create(&params->philo[i].ptid, NULL, &routine, \
		&params->philo[i]);
		i++;
	}
	i = 0;
	while (i < params->n_philo)
	{
		pthread_join(params->philo[i].ptid, NULL);
		i++;
	}
	pthread_mutex_destroy(&params->mutex);
}
