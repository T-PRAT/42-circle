/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:27:56 by tprat             #+#    #+#             */
/*   Updated: 2021/06/04 14:33:27 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server.h"

void	print_binary(char *bin)
{
	char	c;

	c = 0;
	c += (bin[0] - 48) * 128;
	c += (bin[1] - 48) * 64;
	c += (bin[2] - 48) * 32;
	c += (bin[3] - 48) * 16;
	c += (bin[4] - 48) * 8;
	c += (bin[5] - 48) * 4;
	c += (bin[6] - 48) * 2;
	c += (bin[7] - 48) * 1;
	ft_putchar_fd(c, 1);

}

void	handler(int	signum)
{
	static char	*bin;
	static int	i;

	if (!bin)
		bin = malloc(sizeof(char) * 8);
	if (signum == SIGUSR1)
	{
		ft_putnbr_fd(0,1);
		bin[i] = '0';
	}
	else if (signum == SIGUSR2)
	{
		ft_putnbr_fd(1,1);
		bin[i] = '1';
	}
	i++;
	if (i >= 8 && bin)
	{
		print_binary(bin);
		i = 0;
		free(bin);
	}

}

int	main(void)
{
	pid_t				pid;
	struct sigaction	act;

	pid = getpid();
	ft_putstr_fd("PID:", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	act.sa_handler = &handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
