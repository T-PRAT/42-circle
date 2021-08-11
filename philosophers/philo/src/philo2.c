/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:13:06 by tprat             #+#    #+#             */
/*   Updated: 2021/08/11 15:47:07 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_simulation(t_params *params)
{
	int	j;

	j = 0;
	params->t_die = -1;
	while (j < params->n_philo)
	{
		pthread_detach(params->philo[j].ptid);
		j++;
	}
	return ;
}

void	ft_usleep(int time_in_ms)
{
	int	start_time;

	start_time = get_timestamp();
	while ((get_timestamp() - start_time) < time_in_ms)
		usleep(time_in_ms / 10);
}
