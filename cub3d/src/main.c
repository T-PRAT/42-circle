/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 17:20:47 by tprat             #+#    #+#             */
/*   Updated: 2021/05/06 17:08:26 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int main(int ac, char **av)
{
	t_rcs   *rcs;

	rcs = malloc(sizeof(t_rcs));
	if (!rcs)
		return (0);
	rcs->save = false;
	if (ac == 3)
	{
		if (ft_strncmp(av[2], "--save", 7) == 0)
			rcs->save = true;
		else
		{
			ft_putstr_fd("to many arguments", 2);
			return (0);
		}
	}
	if (ac < 2 || ac > 3)
	{
		ft_putstr_fd("to many arguments", 2);
		return (0);
	}
	rcs = parse_map(rcs, av[1]);
	if (!rcs)
		ft_putstr_fd("Error\n", 2);
	else
	{
		//printf("width:%d\nheight:%d\ntext_N:%s\ntext_S:%s\ntext_W:%s\ntext_E:%s\nsprite:%s\ncolor_f:%d\ncorlor_c:%d\nmap:\n>>>%s<<<\n", rcs->res_w, rcs->res_h, rcs->texts[0].path, rcs->texts[1].path, rcs->texts[2].path, rcs->texts[3].path, rcs->texts[4].path, rcs->color_f, rcs->color_c, rcs->map);
		if (!(loop(rcs)))
			return (0);
	}
	return (0);
}
