/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:40:16 by tprat             #+#    #+#             */
/*   Updated: 2021/06/04 14:19:55 by tprat            ###   ########lyon.fr   */
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

void	char_to_bits(char c, int *tab)
{
	tab[7] = c % 2;
	c /= 2;
	tab[6] = c % 2;
	c /= 2;
	tab[5] = c % 2;
	c /= 2;
	tab[4] = c % 2;
	c /= 2;
	tab[3] = c % 2;
	c /= 2;
	tab[2] = c % 2;
	c /= 2;
	tab[1] = c % 2;
	c /= 2;
	tab[0] = c % 2;
}

void	send_str(pid_t ser_pid, char *str)
{
	int	i;
	int	j;
	int	tab[8];

	i = 0;
	while (str[i])
	{
		j = 0;
		char_to_bits(str[i], tab);
		while (j < 8)
		{
			ft_putnbr_fd(tab[j], 1);
			if (tab[j] == 0)
				kill(ser_pid, SIGUSR1);
			else if (tab[j] == 1)
				kill(ser_pid, SIGUSR2);
			usleep(100);
			j++;
		}
		i++;
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
		send_str(ft_atoi(av[1]), av[2]);
	}
	return (0);
}
