/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 00:28:07 by tprat             #+#    #+#             */
/*   Updated: 2021/03/04 16:04:08 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_map	*ray_steps(t_map *map)
{
	int hit;
	int map_x;
    int map_y;

	hit = 0;
	map_x = map->pos_x;
	map_y = map->pos_y;
}

void	raycasting(t_map *map, t_loop *loop)
{
	int	x;

	x = 0;
	while (x < map->res_w)
	{
		map->cam_x = 2 * x / (double)(map->res_w) - 1;
		map->ray_x = map->dir_x + map->pla_x * map->cam_x;
		map->ray_y = map->dir_y + map->pla_y * map->cam_x;
		map->delta_x = 	abs(1 / map->ray_x);
		map->delta_y = 	abs(1 / map->ray_y);

		map = ray_steps(map);
		//printf("res_w:%fcam_x:%f\n", (double)map->res_w, map->cam_x);
		printf("ray_x:%f||ray_y:%f\n", map->ray_x, map->ray_y);
		x++;
	}
}