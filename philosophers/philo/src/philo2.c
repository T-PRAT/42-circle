/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:13:06 by tprat             #+#    #+#             */
/*   Updated: 2021/08/10 15:16:50 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_simulation(t_params *params, int i)
{
	int	j;

	j = 0;
	params->t_die = -1;
	while (j < params->n_philo)
	{
		pthread_detach(params->philo[j].ptid);
		j++;
	}
	printf("%d %d died\n", get_timestamp(), \
	params->philo[i].num);
}
