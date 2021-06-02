/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:27:56 by tprat             #+#    #+#             */
/*   Updated: 2021/06/02 17:03:43 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server.h"

void	handler(int	signum)
{
	if (signum == SIGUSR1)
		write(1, "1", 1);
	if (signum == SIGUSR2)
		write(1, "2", 1);
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
	//signal(SIGUSR1, print_mess);
	//signal(SIGUSR2, print_mess);
	while (1)
		pause();
	return (0);
}
