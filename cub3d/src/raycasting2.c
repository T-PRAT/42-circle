/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:33:08 by tprat             #+#    #+#             */
/*   Updated: 2021/05/05 17:43:26 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_move2(t_rcs *rcs)
{
	double	old_dir_x;
	double	old_pla_x;

	if (rcs->key->left == true)
	{
		if (is_wall((int)(rcs->pos_x - rcs->pla_x * MS), (int)rcs->pos_y, rcs))
			rcs->pos_x -= rcs->pla_x * MS;
		if (is_wall((int)rcs->pos_x, (int)(rcs->pos_y - rcs->pla_y * MS), rcs))
			rcs->pos_y -= rcs->pla_y * MS;
	}
	if (rcs->key->rot_right == true)
	{
		old_dir_x = rcs->dir_x;
		rcs->dir_x = rcs->dir_x * cos(-RS) - rcs->dir_y * sin(-RS);
		rcs->dir_y = old_dir_x * sin(-RS) + rcs->dir_y * cos(-RS);
		old_pla_x = rcs->pla_x;
		rcs->pla_x = rcs->pla_x * cos(-RS) - rcs->pla_y * sin(-RS);
		rcs->pla_y = old_pla_x * sin(-RS) + rcs->pla_y * cos(-RS);
	}
	if (rcs->key->rot_left == true)
	{
		old_dir_x = rcs->dir_x;
		rcs->dir_x = rcs->dir_x * cos(RS) - rcs->dir_y * sin(RS);
		rcs->dir_y = old_dir_x * sin(RS) + rcs->dir_y * cos(RS);
		old_pla_x = rcs->pla_x;
		rcs->pla_x = rcs->pla_x * cos(RS) - rcs->pla_y * sin(RS);
		rcs->pla_y = old_pla_x * sin(RS) + rcs->pla_y * cos(RS);
	}
}

void	check_move(t_rcs *rcs)
{
	if (rcs->key->forward == true)
	{
		if (is_wall((int)(rcs->pos_x + rcs->dir_x * MS), (int)rcs->pos_y, rcs))
			rcs->pos_x += rcs->dir_x * MS;
		if (is_wall((int)rcs->pos_x, (int)(rcs->pos_y + rcs->dir_y * MS), rcs))
			rcs->pos_y += rcs->dir_y * MS;
	}
	if (rcs->key->backward == true)
	{
		if (is_wall((int)(rcs->pos_x - rcs->dir_x * MS), (int)rcs->pos_y, rcs))
			rcs->pos_x -= rcs->dir_x * MS;
		if (is_wall((int)rcs->pos_x, (int)(rcs->pos_y - rcs->dir_y * MS), rcs))
			rcs->pos_y -= rcs->dir_y * MS;
	}
	if (rcs->key->right == true)
	{
		if (is_wall((int)(rcs->pos_x + rcs->pla_x * MS), (int)rcs->pos_y, rcs))
			rcs->pos_x += rcs->pla_x * MS;
		if (is_wall((int)rcs->pos_x, (int)(rcs->pos_y + rcs->pla_y * MS), rcs))
			rcs->pos_y += rcs->pla_y * MS;
	}
	check_move2(rcs);
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
	//printf("side:%d||mapy:%f||posy:%f||stepy:%f||diry:%f||rayy:%f||perp_d:%f\n", rcs->side,(double)rcs->map_y, rcs->pos_y, (double)rcs->step_y,rcs->dir_y, rcs->ray_y, rcs->perp_d);
	//printf("side:%d||mapx:%f||posx:%f||stepx:%f||dirx:%f||rayx:%f||perp_d:%f\n", rcs->side,(double)rcs->map_x, rcs->pos_x, (double)rcs->step_x,rcs->dir_x, rcs->ray_x, rcs->perp_d);
	//printf("side:%d||wallx:%f||textx:%d||width:%d\n", rcs->side, rcs->wall_x, rcs->text_x, rcs->texts[0].width);
	return (rcs);
}

int	select_texture(t_rcs *rcs)
{
	if (rcs->side == 0 && rcs->ray_x < 0)
		return (1);
	else if (rcs->side == 0 && rcs->ray_x >= 0)
		return (0);
	else if (rcs->side == 1 && rcs->ray_y < 0)
		return (3);
	else if (rcs->side == 1 && rcs->ray_y >= 0)
		return (2);
	else
		return (0);
}

void	draw_line(t_rcs *rcs, t_data *data, int x)
{
	int		start;
	int		end;
	int		c;
	double	step;
	double	text_p;

	c = -1;
	rcs = calc_wall(rcs);
	//printf("perp_d:%f\n", rcs->perp_d);
	rcs->wall_h = (rcs->res_h / rcs->perp_d);
	start = -rcs->wall_h / 2 + rcs->res_h / 2;
	if (start < 0)
		start = 0;
	end = rcs->wall_h / 2 + rcs->res_h / 2;
	if (end >= (rcs->res_h))
		end = rcs->res_h - 1;
	//1.0 * ???
	step = 1.0 * (double)rcs->texts[0].height / (double)rcs->wall_h;
	text_p = (double)(start - rcs->res_h / 2) * step;
	//printf("x:%d\n", x);
	rcs->perp_ds[x] = rcs->perp_d;
	//printf("rcs->wall_h:%dstrart:%d||end:%d||step:%f\n", rcs->wall_h, start, end, step);
	while (c++ < start)
		insert_pixel(data, x, c, rcs->color_c);
	while (start < end)
	{
		rcs->text_y = (int)text_p & (rcs->texts[0].height - 1);
		text_p += step;
		insert_pixel(data, x, start, get_pixel(&rcs->texts[select_texture(rcs)], rcs->text_x, rcs->text_y));
		start++;
	}
	start--;
	while (start++ < rcs->res_h - 1)
		insert_pixel(data, x, start, rcs->color_f);
	//if (rcs->spr->spr_pos_x >= 0)
		//draw_sprite(rcs, data, x);
}
