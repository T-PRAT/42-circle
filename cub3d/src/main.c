/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 17:20:47 by tprat             #+#    #+#             */
/*   Updated: 2021/05/07 16:35:31 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	early_error(char *str, t_rcs *rcs)
{
	if (rcs->map)
		free(rcs->map);
	if (rcs)
		free(rcs);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_rcs	*rcs;

	rcs = malloc(sizeof(t_rcs));
	if (!rcs)
		return (0);
	rcs->save = false;
	rcs->map = NULL;
	if (ac == 3)
	{
		if (ft_strncmp(av[2], "--save", 7) == 0)
			rcs->save = true;
		else
			early_error("trop d'arguments", rcs);
	}
	if (ac < 2 || ac > 3)
		early_error("trop d'arguments", rcs);
	rcs = parse_map(rcs, av[1]);
	if (!rcs)
		early_error("Erreur lors du parsing\n", rcs);
	else
	{
		if (!(loop(rcs)))
			return (0);
	}
	return (0);
}
