/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:33:08 by tprat             #+#    #+#             */
/*   Updated: 2021/03/16 14:54:50 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"

double	wall_height(t_map *map)
{
	double	ray_l;

	if (map->side == 0)
			ray_l = ((double)map->map_x - map->pos_x + \
			(1 - (double)map->step_x) / 2) / map->dir_x;
	else
			ray_l = ((double)map->map_y - map->pos_y + \
			(1 - (double)map->step_y) / 2) / map->dir_y;
	printf("side:%d||mapy:%f||posy:%f||stepy:%f||diry:%f||ray_l:%f\n", map->side,(double)map->map_y, map->pos_y, (double)map->step_y, map->dir_y, ray_l);
	printf("side:%d||mapx:%f||posx:%f||stepx:%f||dirx:%f||ray_x:%f\n", map->side,(double)map->map_x, map->pos_x, (double)map->step_x, map->dir_x, ray_l);
	map->wall_h = (int)(map->res_h / map->ray_l);
	return (ray_l);
}

void	draw_line(t_map *map, t_data *data)
{
	map->ray_l = wall_height(map);
	//printf("||%f||\n", map->ray_l);
}