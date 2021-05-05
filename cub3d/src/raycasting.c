/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 00:28:07 by tprat             #+#    #+#             */
/*   Updated: 2021/05/05 15:39:12 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_map *ray_steps(t_map *map)
{
	while (check_wall(map->map_x, map->map_y, map))
	{
		if (map->side_x < map->side_y)
		{
			map->side_x += map->delta_x;
			map->map_x += map->step_x;
			map->side = 0;
		}
		else
		{
			map->side_y += map->delta_y;
			map->map_y += map->step_y;
			map->side = 1;
		}
		if (check_wall(map->map_x, map->map_y, map) == 2)
		{
			map->spr->spr_pos_x = map->map_x;
			map->spr->spr_pos_y = map->map_y;
			//write(1 , "a", 1);
		}
	}
	return (map);
}

t_map *ray_steps_init(t_map *map)
{
	if (map->ray_x < 0)
	{
		map->step_x = -1;
		map->side_x = (map->pos_x - (double)map->map_x) * map->delta_x;
	}
	else
	{
		map->step_x = 1;
		map->side_x = ((double)map->map_x + 1 - map->pos_x) * map->delta_x;
	}
	if (map->ray_y < 0)
	{
		map->step_y = -1;
		map->side_y = (map->pos_y - (double)map->map_y) * map->delta_y;
	}
	else
	{
		map->step_y = 1;
		map->side_y = ((double)map->map_y + 1 - map->pos_y) * map->delta_y;
	}
	//printf ("sidex:%f|||sidey:%f\n", map->side_x, map->side_y);
	return (ray_steps(map));
}

void	start_raycast(t_map *map, t_data *data)
{
	int x;

	x = 0;
	while (x < map->res_w)
	{
		map->spr->spr_pos_x = -1;
		map->cam_x = 2 * x / (double)(map->res_w) - 1;
		map->ray_x = map->dir_x + map->pla_x * map->cam_x;
		map->ray_y = map->dir_y + map->pla_y * map->cam_x;
		map->map_x = (int)map->pos_x;
		map->map_y = (int)map->pos_y;
		if (map->ray_y == 0)
			map->delta_x = 0;
		else
		{
			if (map->ray_x == 0)
				map->delta_x = 1;
			else
				map->delta_x = fabs(1 / map->ray_x);
		}
		if (map->ray_x == 0)
			map->delta_y = 0;
		else
		{
			if (map->ray_y == 0)
				map->delta_y = 1;
			else
				map->delta_y = fabs(1 / map->ray_y);
		}
		map = ray_steps_init(map);
		draw_line(map, data, x);
		//printf("res_w:%fcam_x:%f\n", (double)map->res_w, map->cam_x);
		//printf("ray_x:%f||ray_y:%f\n", map->ray_x, map->ray_y);
		x++;
	}
}

int	raycasting(t_data *data)
{
	data->map->spr->spr_pos_x = -1;
	data->map->spr->spr_pos_y = -1;
	start_raycast(data->map, data);
	if (data->map->save == true)
		return (1);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	check_move(data->map);
	return (1);
}
