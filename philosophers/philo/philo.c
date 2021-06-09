/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:43:22 by tprat             #+#    #+#             */
/*   Updated: 2021/06/09 19:01:54 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *vparams)
{
	t_params	*params;

	params = vparams;
	printf("nb_philo:\n");
	return (0);
}

void	start_philos(t_params *params)
{
	int				i;
	int				ret;
	pthread_t		ptid;

	i = 0;
	ret = pthread_create(&ptid, NULL, &routine, params);
	pthread_join(ptid, NULL);
	/*while (i < params->n_philo)
	{
	}*/
}
