/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:43:22 by tprat             #+#    #+#             */
/*   Updated: 2021/08/11 16:11:20 by tprat            ###   ########lyon.fr   */
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
				printf("%d %d died\n", get_timestamp(), params->philo[i].num);
				return (end_simulation(params));
			}
			if (params->philo[i].n_eat == 0)
				c++;
		}
		if (c == params->n_philo)
			return (end_simulation(params));
		ft_usleep(1);
	}
}

void	take_fork(t_philo *philo)
{
	if (philo->params->t_die == -1)
		return ;
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
		if (philo->params->t_die != -1 && philo->n_eat != 0)
			printf("%d %d is thinking\n", get_timestamp(), philo->num);
		take_fork(philo);
		if (philo->params->t_die != -1 && philo->n_eat != 0)
			printf("%d %d is eating\n", get_timestamp(), philo->num);
		pthread_mutex_lock(&philo->eat);
		philo->l_eat = get_timestamp();
		pthread_mutex_unlock(&philo->eat);
		philo->s_eat = 1;
		ft_usleep(philo->params->t_eat);
		philo->s_eat = 0;
		philo->n_eat--;
		pthread_mutex_unlock(&philo->params->fork[philo->num - 1]);
		pthread_mutex_unlock(&philo->params->fork[(philo->num) % \
		philo->params->n_philo]);
		if (philo->params->t_die != -1 && philo->n_eat != 0)
			printf("%d %d is sleeping\n", get_timestamp(), philo->num);
		ft_usleep(philo->params->t_sleep);
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
	i = -1;
	while (ret == 0 && ++i < params->n_philo)
	{
		ret = pthread_create(&params->philo[i].ptid, NULL, &routine, \
		&params->philo[i]);
	}
	monitor(params);
	i = -1;
	while (++i < params->n_philo)
	{
		pthread_mutex_destroy(&params->fork[i]);
		pthread_mutex_destroy(&params->philo[i].eat);
	}
}
