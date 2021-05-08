/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:33:08 by tprat             #+#    #+#             */
/*   Updated: 2021/05/07 15:56:08:00prat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_sprite(t_rcs *rcs)
{
	t_spr	*current;

	current = rcs->spr;
	if (!current)
		rcs = new_sprite_list(rcs);
	else
	{
		while (current->next)
		{
			if (current->spr_pos_x == rcs->map_x && \
			current->spr_pos_y == rcs->map_y)
				return (0);
			current = current->next;
		}
		if (current->spr_pos_x != rcs->map_x || \
		current->spr_pos_y != rcs->map_y)
			rcs = new_sprite_list(rcs);
	}
	return (0);
}

t_rcs	*calc_wall(t_rcs *rcs)
{
	if (rcs->side == 0)
	{
		rcs->perp_d = ((double)rcs->map_x - rcs->pos_x + \
		((double)(1 - rcs->step_x)) / 2) / rcs->ray_x;
		rcs->wall_x = rcs->pos_y + rcs->perp_d * rcs->ray_y;
	}
	else
	{
		rcs->perp_d = ((double)rcs->map_y - rcs->pos_y + \
		((double)(1 - rcs->step_y)) / 2) / rcs->ray_y;
		rcs->wall_x = rcs->pos_x + rcs->perp_d * rcs->ray_x;
	}
	rcs->wall_x -= floor(rcs->wall_x);
	rcs->text_x = (int)(rcs->wall_x * rcs->texts[0].width);
	if (rcs->side == 0 && rcs->ray_x > 0)
		rcs->text_x = rcs->texts[0].width - rcs->text_x - 1;
	if (rcs->side == 1 && rcs->ray_y < 0)
		rcs->text_x = rcs->texts[0].width - rcs->text_x - 1;
	return (rcs);
}

int	select_texture(t_rcs *rcs)
{
	if (rcs->side == 0 && rcs->ray_x < 0)
		return (3);
	else if (rcs->side == 0 && rcs->ray_x >= 0)
		return (2);
	else if (rcs->side == 1 && rcs->ray_y < 0)
		return (0);
	else if (rcs->side == 1 && rcs->ray_y >= 0)
		return (1);
	else
		return (0);
}

void	calc_start_end(t_rcs *rcs)
{
	rcs->start = -rcs->wall_h / 2 + rcs->res_h / 2;
	if (rcs->start < 0)
		rcs->start = 0;
	rcs->end = rcs->wall_h / 2 + rcs->res_h / 2;
	if (rcs->end >= (rcs->res_h))
		rcs->end = rcs->res_h - 1;
}

void	draw_line(t_rcs *rcs, t_data *data, int x)
{
	int		c;
	double	step;
	double	text_p;

	c = -1;
	rcs = calc_wall(rcs);
	rcs->wall_h = (rcs->res_h / rcs->perp_d);
	calc_start_end(rcs);
	step = 1.0 * (double)rcs->texts[0].height / (double)rcs->wall_h;
	text_p = step * (double)(rcs->start - rcs->res_h / 2);
	rcs->perp_ds[x] = rcs->perp_d;
	while (c++ < rcs->start)
		insert_pixel(data, x, c, rcs->color_c);
	while (rcs->start++ < rcs->end - 1)
	{
		rcs->text_y = (int)text_p & (rcs->texts[0].height - 1);
		text_p += step;
		insert_pixel(data, x, rcs->start, \
		get_pixel(&rcs->texts[select_texture(rcs)], rcs->text_x, rcs->text_y));
	}
	rcs->start--;
	while (rcs->start++ < rcs->res_h - 1)
		insert_pixel(data, x, rcs->start, rcs->color_f);
}
