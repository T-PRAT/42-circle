/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 00:28:07 by tprat             #+#    #+#             */
/*   Updated: 2021/03/05 14:48:07 by tprat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		check_wall(t_map *map)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (map->map[i++]);
	i--;
	while (map->map[i] && c < map->map_y)
		i--;
	while (map->map[i - 1] != '\n')
		i--;
	if (map->map[i + map->map_x] != 1)
		return (0);
	return (1);
}

t_map	*ray_steps(t_map *map)
{
	while (!(check_wall(map)))
	{
		if (map->side_x < map->side_y)
		{
			map->side_x += map->delta_x;
			map->map_x = map->step_x;
			map->side = 0;
		}
		else
		{
			map->side_y += map->delta_y;
			map->map_y = map->step_y;
			map->side = 1;
		}
		//printf("mapx:%d|||mapy:%d\n", map->map_x, map->map_y);
		return (map);
	}
}

t_map	*ray_steps_init(t_map *map)
{
	if (map->ray_x < 0)
	{
		map->step_x = -1.0;
		map->side_x = (map->pos_x - map->map_x) 	* map->delta_x;
	}
	else
	{
		map->step_x = 1;
		map->side_x = (map->map_x + 1 - map->pos_x)	* map->delta_x;
	}
	if (map->ray_y < 0)
	{
		map->step_y = -1;
		map->side_y = (map->pos_y - map->map_y) * map->delta_y;
	}
	else
	{
		map->step_y = 1;
		map->side_y = (map->map_x + 1 - map->pos_y)	* map->delta_y;
	}
	//printf ("stepx:%f|||stepy:%f\n", map->side_x, map->side_y);
	return (ray_steps(map));
}

t_map	*raycasting(t_map *map, t_loop *loop)
{
	int	x;

	x = 0;
	while (x < map->res_w)
	{
		map->cam_x = 2 * x / (double)(map->res_w) - 1;
		map->ray_x = map->dir_x + map->pla_x * map->cam_x;
		map->ray_y = map->dir_y + map->pla_y * map->cam_x;
		map->map_x = (int)map->pos_x;
		map->map_y = (int)map->pos_y;
		printf("mapx%d\n", map->map_x);
		if (map->ray_y == 0)
			map->delta_x = 0;
		else
		{
			if (map->ray_x == 0)
				map->delta_x;
			else
				map->delta_x = abs(1 / map->ray_x);
		}
		if (map->ray_x == 0)
			map->delta_y = 0;
		else
		{
			if (map->ray_y == 0)
				map->delta_y;
			else
				map->delta_y = abs(1 / map->ray_y);
		}
		map = ray_steps_init(map);
		//printf("res_w:%fcam_x:%f\n", (double)map->res_w, map->cam_x);
		//printf("ray_x:%f||ray_y:%f\n", map->ray_x, map->ray_y);
		x++;
	}
	return (map);
}
