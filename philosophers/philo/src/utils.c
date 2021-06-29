/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:59:22 by tprat             #+#    #+#             */
/*   Updated: 2021/06/29 19:43:09 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_timestamp(void)
{
	struct timeval	curr_time;
	static int		timebase = 0;

	if (timebase == 0)
	{
		gettimeofday(&curr_time, NULL);
		timebase = curr_time.tv_sec * 1000 + curr_time.tv_usec / 1000;
	}
	gettimeofday(&curr_time, NULL);
	return (curr_time.tv_sec * 1000 + curr_time.tv_usec / 1000 - timebase);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
		write(fd, s, i);
	}
}

void	ft_error(char *str, t_params *params)
{
	if (params)
	{
		if (params->philo)
			free(params->philo);
		if (params->fork)
			free(params->fork);
		free(params);
	}
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			sign *= -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * sign);
}

int	is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}
