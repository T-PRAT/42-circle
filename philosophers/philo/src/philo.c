/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:43:22 by tprat             #+#    #+#             */
/*   Updated: 2021/06/23 20:25:44 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	second_fork(int	num, int n_philo)
{
	if (num == 0)
		return (n_philo - 1);
	else
		return (num - 1);
}

void	*routine(void *arg)
{
	t_philo			*philo;

	philo = arg;
	pthread_mutex_lock(&philo->params->fork[philo->num]);
	pthread_mutex_lock(&philo->params->fork[second_fork(philo->num, \
	philo->params->n_philo)]);
	usleep(philo->t_eat);
	gettimeofday(&philo->params->curr_time, NULL);
	printf("%ld:%d\n", philo->params->curr_time.tv_sec, \
	philo->params->curr_time.tv_usec);
	printf("philo %d is eating\n", philo->num);
	pthread_mutex_unlock(&philo->params->fork[philo->num]);
	pthread_mutex_unlock(&philo->params->fork[second_fork(philo->num, \
	philo->params->n_philo)]);
	usleep(philo->t_sleep);
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
	params->curr_time.tv_sec = 0;
	params->curr_time.tv_usec = 0;
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
		//usleep(100);
	}
	i = -1;
	while (++i < params->n_philo)
		pthread_join(params->philo[i].ptid, NULL);
	i = -1;
	while (++i < params->n_philo)
		pthread_mutex_destroy(&params->fork[i]);
}
