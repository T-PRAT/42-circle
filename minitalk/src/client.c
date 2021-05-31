/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:40:16 by tprat             #+#    #+#             */
/*   Updated: 2021/05/31 18:15:07 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server.h"

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		ft_putstr_fd("nombre d'arguments incorrect\n")
		return (1);
	}
	return (0);
}
