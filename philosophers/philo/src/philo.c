/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:43:22 by tprat             #+#    #+#             */
/*   Updated: 2021/06/30 15:09:03 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitor(t_params *params)
{
	int	i;
	int	c;

	c = 0;
	while (42)
	{
		i = 0;
		while (i < params->n_philo)
		{
			if (get_timestamp() - params->philo[i].l_eat > params->t_die)
			{
				params->t_die = -1;
				printf("%d philo %d died\n", get_timestamp(), \
				params->philo[i].num);
				return ;
			}
			if (params->philo[i].n_eat == 0)
				c++;
			i++;
		}
		if (c == params->n_philo)
			return ;
		usleep(100);
	}
}

void	take_fork(t_philo *philo)
{
	if (philo->params->t_die == -1)
		return ;
	else if (philo->num % 2)
	{
		pthread_mutex_lock(&philo->params->fork[philo->num - 1]);
		printf("%d philo %d has taken a fork\n", get_timestamp(), philo->num);
		pthread_mutex_lock(&philo->params->fork[(philo->num) % \
		philo->params->n_philo]);
		printf("%d philo %d has taken a fork\n", get_timestamp(), philo->num);
	}
	else
	{
		pthread_mutex_lock(&philo->params->fork[(philo->num) % \
		philo->params->n_philo]);
		printf("%d philo %d has taken a fork\n", get_timestamp(), philo->num);
		pthread_mutex_lock(&philo->params->fork[philo->num - 1]);
		printf("%d philo %d has taken a fork\n", get_timestamp(), philo->num);
	}
}

void	*routine(void *arg)
{
	t_philo			*philo;

	philo = arg;
	while (philo->params->t_die > 0 && philo->n_eat != 0)
	{
		if (philo->params->t_die != -1)
			printf("%d philo %d is thinking\n", get_timestamp(), philo->num);
		take_fork(philo);
		if (philo->params->t_die != -1)
			printf("%d philo %d is eating\n", get_timestamp(), philo->num);
		philo->l_eat = get_timestamp();
		usleep(philo->params->t_eat * 1000);
		if (philo->n_eat != -1)
			philo->n_eat--;
		pthread_mutex_unlock(&philo->params->fork[philo->num - 1]);
		pthread_mutex_unlock(&philo->params->fork[(philo->num) % \
		philo->params->n_philo]);
		if (philo->params->t_die != -1)
			printf("%d philo %d is sleeping\n", get_timestamp(), philo->num);
		usleep(philo->params->t_sleep * 1000);
	}
	return (0);
}

void	init_philo(t_params *params)
{
	int	i;

	i = 0;
	params->philo = malloc(sizeof(t_philo) * params->n_philo);
	if (!params->philo)
		ft_error("error : malloc failed\n", params);
	params->fork = malloc(sizeof(pthread_mutex_t) * params->n_philo);
	if (!params->fork)
		ft_error("error : malloc failed\n", params);
	while (i < params->n_philo)
	{
		params->philo[i].num = i + 1;
		params->philo[i].n_eat = params->n_eat;
		params->philo->l_eat = get_timestamp();
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
		usleep(100);
	}
	monitor(params);
	i = -1;
	while (++i < params->n_philo)
		pthread_mutex_destroy(&params->fork[i]);
}
