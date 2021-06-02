/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:40:16 by tprat             #+#    #+#             */
/*   Updated: 2021/06/02 20:11:07 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server.h"

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
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

int	send_str(int ser_pid, char *str)
{
	int		i;
	int		tmp;
	char	c[8];

	i = 0;
	while (str[i])
	{
		tmp = str[i];
		while (tmp > 0)
		{
			tmp = tmp / 2;
		}


	}
}

int	main(int ac, char **av)
{
	if (ac != 3)
		ft_error("nombre d'arguments incorrect\n");
	if (!is_num(av[1]))
		ft_error("PID incorrect\n");
	else
	{
		send_str(av[1], av[2]);
		kill(ft_atoi(av[1]), SIGUSR1);
		usleep(1);
		kill(ft_atoi(av[1]), SIGUSR2);
		usleep(1);
		kill(ft_atoi(av[1]), SIGUSR2);
		usleep(1);
		kill(ft_atoi(av[1]), SIGUSR1);
		usleep(1);
		kill(ft_atoi(av[1]), SIGUSR1);
		usleep(1);
		kill(ft_atoi(av[1]), SIGUSR2);
	}
	return (0);
}
