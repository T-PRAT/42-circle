/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:43:22 by tprat             #+#    #+#             */
/*   Updated: 2021/08/10 17:52:57 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitor(t_params *params)
{
	int	i;
	int	c;
	int	delta;

	c = 0;
	while (42)
	{
		i = -1;
		while (++i < params->n_philo)
		{
			pthread_mutex_lock(&params->philo->eat);
			delta = get_timestamp() - params->philo[i].l_eat;
			pthread_mutex_unlock(&params->philo->eat);
			if (delta > params->t_die && params->philo[i].s_eat != 1)
			{
				end_simulation(params, i);
				return ;
			}
			if (params->philo[i].n_eat == 0)
				c++;
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
	/*if (!(philo->num % 2))
		pthread_mutex_lock(&philo->params->fork[(philo->num) % \
		philo->params->n_philo]);
	else
		pthread_mutex_lock(&philo->params->fork[philo->num - 1]);
	printf("%d %d has taken a fork\n", get_timestamp(), philo->num);
	if (philo->params->n_philo == 1)
	{
		pthread_mutex_lock(&philo->params->fork[(philo->num) % \
		philo->params->n_philo]);
		return ;
	}
	if (!(philo->num % 2))
	{
		if (pthread_mutex_lock(&philo->params->fork[philo->num - 1]))
		{
			pthread_mutex_lock(&philo->params->fork[(philo->num) % \
			philo->params->n_philo]);
			take_fork(philo);
		}
	}
	else
	{
		if (pthread_mutex_lock(&philo->params->fork[(philo->num) % \
		philo->params->n_philo]))
		{
			pthread_mutex_lock(&philo->params->fork[philo->num - 1]);
			take_fork(philo);
		}
	}*/
	else if (philo->num % 2)
	{
		pthread_mutex_lock(&philo->params->fork[philo->num - 1]);
		printf("%d %d has taken a fork\n", get_timestamp(), philo->num);
		pthread_mutex_lock(&philo->params->fork[(philo->num) % \
		philo->params->n_philo]);
		printf("%d %d has taken a fork\n", get_timestamp(), philo->num);
	}
	else
	{
		pthread_mutex_lock(&philo->params->fork[(philo->num) % \
		philo->params->n_philo]);
		printf("%d %d has taken a fork\n", get_timestamp(), philo->num);
		pthread_mutex_lock(&philo->params->fork[philo->num - 1]);
		printf("%d %d has taken a fork\n", get_timestamp(), philo->num);
	}
}

void	*routine(void *arg)
{
	t_philo			*philo;

	philo = arg;
	while (philo->params->t_die > 0 && philo->n_eat != 0)
	{
		if (philo->params->t_die != -1)
			printf("%d %d is thinking\n", get_timestamp(), philo->num);
		pthread_mutex_lock(&philo->eat);
		take_fork(philo);
		if (philo->params->t_die != -1)
			printf("%d %d is eating\n", get_timestamp(), philo->num);
		philo->l_eat = get_timestamp();
		pthread_mutex_unlock(&philo->eat);
		philo->s_eat = 1;
		usleep(philo->params->t_eat * 1000);
		philo->s_eat = 0;
		if (philo->n_eat != -1)
			philo->n_eat--;
		pthread_mutex_unlock(&philo->params->fork[philo->num - 1]);
		pthread_mutex_unlock(&philo->params->fork[(philo->num) % \
		philo->params->n_philo]);
		if (philo->params->t_die != -1)
			printf("%d %d is sleeping\n", get_timestamp(), philo->num);
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
		pthread_mutex_init(&params->philo[i].eat, NULL);
		params->philo[i].num = i + 1;
		params->philo[i].s_eat = 0;
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
	i = 0;
	while (ret == 0 && i < params->n_philo)
	{
		ret = pthread_create(&params->philo[i].ptid, NULL, &routine, \
		&params->philo[i]);
		i += 2;
	}
	usleep(params->t_eat * 1000);
	i = 1;
	while (ret == 0 && i < params->n_philo)
	{
		ret = pthread_create(&params->philo[i].ptid, NULL, &routine, \
		&params->philo[i]);
		i += 2;
	}
	monitor(params);
	i = -1;
	while (++i < params->n_philo)
		pthread_mutex_destroy(&params->fork[i]);
}
