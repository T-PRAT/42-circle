/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:33:08 by tprat             #+#    #+#             */
/*   Updated: 2021/03/19 15:57:21 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"

double	wall_height(t_map *map)
{
	double	ray_l;

	if (map->side == 0)
		ray_l = ((double)map->map_x - map->pos_x + \
		((double)(1 - map->step_x)) / 2) / map->ray_x;
	else
		ray_l = ((double)map->map_y - map->pos_y + \
		((double)(1 - map->step_y)) / 2) / map->ray_y;
	//printf("side:%d||mapy:%f||posy:%f||stepy:%f||rayy:%f||ray_l:%f\n", map->side,(double)map->map_y, map->pos_y, (double)map->step_y, map->ray_y, ray_l);
	//printf("side:%d||mapx:%f||posx:%f||stepx:%f||rayx:%f||ray_x:%f\n", map->side,(double)map->map_x, map->pos_x, (double)map->step_x, map->ray_x, ray_l);
	return (ray_l);
}

void	draw_line(t_map *map, t_data *data, int x)
{
	int	wall_h;
	int	start;
	int	end;
	int c;

	c = -1;
	map->ray_l = wall_height(map);
	//printf("ray_l:%f\n", map->ray_l);
	wall_h = (map->res_h / map->ray_l);
	start = -wall_h / 2 + map->res_h / 2;
	if (start < 0)
		start = 0;
	end = wall_h / 2 + map->res_h / 2;
	if (end >= (map->res_h))
		end = map->res_h - 1;
	//printf("wall_h:%dstrart:%d||end:%d\n", wall_h, start, end);
	while (c++ < start)
		insert_pixel(data, x, c, map->color_c);
	while (start < end)
	{
		if (map->side == 1)
			insert_pixel(data, x, start, 0x00FFDD00);
		else
			insert_pixel(data, x, start, 0x00FFFF00);
		start++;
	}
	while (start++ < map->res_h -1)
		insert_pixel(data, x, start, map->color_f);
}