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

void	check_move2(t_map *map)
{
	double	old_dir_x;
	double	old_pla_x;

	if (map->key->left == true)
	{
		if (check_wall((int)(map->pos_x - map->pla_x * MS), (int)map->pos_y, map))
			map->pos_x -= map->pla_x * MS;
		if (check_wall((int)map->pos_x, (int)(map->pos_y - map->pla_y * MS),map))
			map->pos_y -= map->pla_y * MS;
	}
	if (map->key->rot_right == true)
	{
		old_dir_x = map->dir_x;
		map->dir_x = map->dir_x * cos(-RS) - map->dir_y * sin(-RS);
		map->dir_y = old_dir_x * sin(-RS) + map->dir_y * cos(-RS);
		old_pla_x = map->pla_x;
		map->pla_x = map->pla_x * cos(-RS) - map->pla_y * sin(-RS);
		map->pla_y = old_pla_x * sin(-RS) + map->pla_y * cos(-RS);
	}
	if (map->key->rot_left == true)
	{
		old_dir_x = map->dir_x;
		map->dir_x = map->dir_x * cos(RS) - map->dir_y * sin(RS);
		map->dir_y = old_dir_x * sin(RS) + map->dir_y * cos(RS);
		old_pla_x = map->pla_x;
		map->pla_x = map->pla_x * cos(RS) - map->pla_y * sin(RS);
		map->pla_y = old_pla_x * sin(RS) + map->pla_y * cos(RS);
	}
}

void	check_move(t_map *map)
{
	if (map->key->forward == true)
	{
		if (check_wall((int)(map->pos_x + map->dir_x * MS), (int)map->pos_y, map))
			map->pos_x += map->dir_x * MS;
		if (check_wall((int)map->pos_x, (int)(map->pos_y + map->dir_y * MS),map))
			map->pos_y += map->dir_y * MS;
	}
	if (map->key->backward == true)
	{
		if (check_wall((int)(map->pos_x - map->dir_x * MS), (int)map->pos_y, map))
			map->pos_x -= map->dir_x * MS;
		if (check_wall((int)map->pos_x, (int)(map->pos_y - map->dir_y * MS),map))
			map->pos_y -= map->dir_y * MS;
	}
	if (map->key->right == true)
	{
		if (check_wall((int)(map->pos_x + map->pla_x * MS), (int)map->pos_y, map))
			map->pos_x += map->pla_x * MS;
		if (check_wall((int)map->pos_x, (int)(map->pos_y + map->pla_y * MS),map))
			map->pos_y += map->pla_y * MS;
	}
	check_move2(map);
}

t_map	*calc_wall(t_map *map)
{
	if (map->side == 0)
	{
		map->ray_l = ((double)map->map_x - map->pos_x + \
		((double)(1 - map->step_x)) / 2) / map->ray_x;
		map->wall_x = map->pos_y + map->ray_l * map->ray_y;
	}
	else
	{
		map->ray_l = ((double)map->map_y - map->pos_y + \
		((double)(1 - map->step_y)) / 2) / map->ray_y;
		map->wall_x = map->pos_x + map->ray_l * map->ray_x;
	}
	map->wall_x -= floor(map->wall_x);
	map->text_x = (int)(map->wall_x * map->texts[0].width);
	if (map->side == 0 &&  map->ray_x > 0)
		map->text_x = map->texts[0].width - map->text_x - 1;
	if (map->side == 1 &&  map->ray_y < 0)
		map->text_x = map->texts[0].width - map->text_x - 1;
	//printf("side:%d||mapy:%f||posy:%f||stepy:%f||diry:%f||rayy:%f||ray_l:%f\n", map->side,(double)map->map_y, map->pos_y, (double)map->step_y,map->dir_y, map->ray_y, map->ray_l);
	//printf("side:%d||mapx:%f||posx:%f||stepx:%f||dirx:%f||rayx:%f||ray_l:%f\n", map->side,(double)map->map_x, map->pos_x, (double)map->step_x,map->dir_x, map->ray_x, map->ray_l);
	//printf("side:%d||wallx:%f||textx:%d||width:%d\n", map->side, map->wall_x, map->text_x, map->texts[0].width);
	return (map);
}

int		select_texture(t_map *map)
{
	if (map->side == 0  && map->ray_x < 0)
		return (1);
	else if (map->side == 0  && map->ray_x >= 0)
		return (0);
	else if (map->side == 1  && map->ray_y < 0)
		return (3);
	else if (map->side == 1  && map->ray_y >= 0)
		return (2);
	else
		return (0);
}

void	draw_line(t_map *map, t_data *data, int x)
{
	int	wall_h;
	int	start;
	int	end;
	int	c;
	double	step;
	double	text_p;
	int		color;

	c = -1;
	map = calc_wall(map);
	color = 0;
	//printf("ray_l:%f\n", map->ray_l);
	wall_h = (map->res_h / map->ray_l);
	start = -wall_h / 2 + map->res_h / 2;
	if (start < 0)
		start = 0;
	end = wall_h / 2 + map->res_h / 2;
	if (end >= (map->res_h))
		end = map->res_h - 1;
	//1.0 * ???
	step = 1.0 * (double)map->texts[0].height / (double)wall_h;
	text_p = (double)(start - map->res_h / 2) * step;
	//printf("wall_h:%dstrart:%d||end:%d||step:%f\n", wall_h, start, end, step);
	//printf("lines:%d||textlines:%dx:%d\n", data->line_s, map->texts[0].line_s, x);
	//printf("x:%d||texx:%d||texy:%d\n", x, map->text_x, map->text_y);
	while (c++ < start)
		insert_pixel(data, x, c, map->color_c);
		//data->img_adr[c * data->line_s + x * (data->bpp / 8)] = map->color_c;
	while (start < end)
	{
		map->text_y = (int)text_p & (map->texts[0].height - 1);
		//printf("||%f||\n", step);
		text_p += step;
		//printf("color:%d\n", get_pixel(&map->texts[0], map->text_x, map->text_y));
		//get_pixel(&map->texts[0], map->text_x, map->text_y, color);
		insert_pixel(data, x, start, get_pixel(&map->texts[select_texture(map)], map->text_x, map->text_y));
		start++;
		//data->img_adr[start * data->line_s + x * (data->bpp / 8)] = map->texts[0].addr[map->text_y * map->texts[0].line_s / 4 + map->text_x];
	}
	start--;
	while (start++ < map->res_h - 1)
		insert_pixel(data, x, start, map->color_f);
		//data->img_adr[start * data->line_s + x * (data->bpp / 8)] = map->color_f;
}
