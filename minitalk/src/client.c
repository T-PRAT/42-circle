/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:40:16 by tprat             #+#    #+#             */
/*   Updated: 2021/06/01 14:53:17 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server.h"

int	main(int ac, char **av)
{
	ft_putstr_fd(av[1], 1);
	if (ac != 3)
	{
		ft_putstr_fd("nombre d'arguments incorrect\n", 1);
		return (1);
	}
	else
	{
		kill(ft_atoi(av[1]), SIGUSR1);
		usleep(1);
		kill(ft_atoi(av[1]), SIGUSR2);
	}
	return (0);
}
