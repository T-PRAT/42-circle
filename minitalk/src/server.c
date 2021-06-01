/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:27:56 by tprat             #+#    #+#             */
/*   Updated: 2021/06/01 14:51:22 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server.h"

void	print_mess(int	signal)
{
	if (signal == SIGUSR1)
		ft_putstr_fd("sigsur1 was sent\n", 1);
	if (signal == SIGUSR2)
		ft_putstr_fd("sigsur2 was sent\n", 1);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	signal(SIGUSR1, print_mess);
	signal(SIGUSR2, print_mess);
	while (1)
		;
	return (0);
}
