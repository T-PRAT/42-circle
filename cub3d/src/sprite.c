/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 10:43:24 by tprat             #+#    #+#             */
/*   Updated: 2021/05/05 14:19:35 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_map	*calc_perp_d(t_map *map)
{
	if (map->side == 0)
	{
		map->spr->perp_d = ((double)map->spr->spr_pos_x - map->pos_x + \
		((double)(1 - map->step_x)) / 2) / map->ray_x;
		map->wall_x = map->pos_y + map->spr->perp_d * map->ray_y;
	}
	else
	{
		map->spr->perp_d = ((double)map->spr->spr_pos_y - map->pos_y + \
		((double)(1 - map->step_y)) / 2) / map->ray_y;
		map->wall_x = map->pos_x + map->spr->perp_d * map->ray_x;
	}
	map->wall_x -= floor(map->wall_x);
	map->spr->spr_x = (int)(map->wall_x * map->texts[4].width);
	if (map->side == 0 &&  map->ray_x > 0)
		map->spr->spr_x = map->texts[4].width - map->spr->spr_x - 1;
	if (map->side == 1 &&  map->ray_y < 0)
		map->spr->spr_x = map->texts[4].width - map->spr->spr_x - 1;
	return (map);
}

t_map	*draw_sprite(t_map *map, t_data *data, int x)
{
	int		spr_h;
	int 	start;
	int		end;
	double	step;
	double	text_p;
	int		color;
	double	face;
	double	trans_x;
	double	trans_y;
	int		spr_t;

	map = calc_perp_d(map);
	face = 1.0 / (map->pla_x * map->dir_y - map->dir_x * map->pla_y);
	trans_x = face * (map->dir_y * map->spr->spr_x - map->dir_x * map->spr->spr_y);
	trans_x = face * (-map->pla_y * map->spr->spr_x + map->pla_x * map->spr->spr_y);
	spr_t = (int)(map->res_w / 2) * (1 + trans_x / trans_y);
	spr_h = (map->res_h / map->spr->perp_d);
	printf("spr_t:%d\n", spr_t);
	start = spr_t;
	if (start < 0)
		start = 0;
	end = spr_h / 2 + map->res_h / 2;
	if (end >= (map->res_h))
		end = map->res_h - 1;
	step = 1.0 * (double)map->texts[4].height / (double)spr_h;
	text_p = (double)(start - map->res_h / 2) * step;
	while (start < end)
	{
		map->spr->spr_y = (int)text_p & (map->texts[4].height - 1);
		text_p += step;
		color = get_pixel(&map->texts[4], map->spr->spr_x, map->spr->spr_y);
		if (color >= 0)
			insert_pixel(data, x, start, color);
		start++;
	}
	//printf("sprh:%d\n", spr_h);
	return (map);
}
