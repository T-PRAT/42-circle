/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 17:20:47 by tprat             #+#    #+#             */
/*   Updated: 2021/03/19 14:29:45 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int main(int ac, char **av)
{
    t_map   *map;

	if(!(map = malloc(sizeof(t_map))))
		return (0);
    if (ac != 2)
    {
        ft_putstr_fd("to many arguments", 2);
        return (0);
    }
    if (!(map = parse_map(av[1])))
        ft_putstr_fd("Error\n", 2);
    else
    {
	    printf("width:%d\nheight:%d\ntext_N:%s\ntext_S:%s\ntext_W:%s\ntext_E:%s\nsprite:%s\ncolor_f:%d\ncorlor_c:%d\nmap:\n>>>%s<<<\n", map->res_w, map->res_h, map->texts[0].path, map->texts[1].path, map->texts[2].path, map->texts[3].path, map->sprite, map->color_f, map->color_c, map->map);
        if (!(loop(map)))
            return (0);
    }
    return (0);
}
