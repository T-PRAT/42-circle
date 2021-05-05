/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 10:43:24 by tprat             #+#    #+#             */
/*   Updated: 2021/05/05 17:11:04 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_rcs	*calc_perp_d(t_rcs *rcs)
{
	if (rcs->side == 0)
	{
		rcs->spr->perp_d = ((double)rcs->spr->spr_pos_x - rcs->pos_x + \
		((double)(1 - rcs->step_x)) / 2) / rcs->ray_x;
		rcs->wall_x = rcs->pos_y + rcs->spr->perp_d * rcs->ray_y;
	}
	else
	{
		rcs->spr->perp_d = ((double)rcs->spr->spr_pos_y - rcs->pos_y + \
		((double)(1 - rcs->step_y)) / 2) / rcs->ray_y;
		rcs->wall_x = rcs->pos_x + rcs->spr->perp_d * rcs->ray_x;
	}
	rcs->wall_x -= floor(rcs->wall_x);
	rcs->spr->spr_x = (int)(rcs->wall_x * rcs->texts[4].width);
	if (rcs->side == 0 &&  rcs->ray_x > 0)
		rcs->spr->spr_x = rcs->texts[4].width - rcs->spr->spr_x - 1;
	if (rcs->side == 1 &&  rcs->ray_y < 0)
		rcs->spr->spr_x = rcs->texts[4].width - rcs->spr->spr_x - 1;
	return (rcs);
}

t_rcs	*draw_sprite(t_rcs *rcs, t_data *data, int x)
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

	rcs = calc_perp_d(rcs);
	face = 1.0 / (rcs->pla_x * rcs->dir_y - rcs->dir_x * rcs->pla_y);
	trans_x = face * (rcs->dir_y * rcs->spr->spr_x - rcs->dir_x * rcs->spr->spr_y);
	trans_x = face * (-rcs->pla_y * rcs->spr->spr_x + rcs->pla_x * rcs->spr->spr_y);
	spr_t = (int)(rcs->res_w / 2) * (1 + trans_x / trans_y);
	spr_h = (rcs->res_h / rcs->spr->perp_d);
	printf("spr_t:%d\n", spr_t);
	start = spr_t;
	if (start < 0)
		start = 0;
	end = spr_h / 2 + rcs->res_h / 2;
	if (end >= (rcs->res_h))
		end = rcs->res_h - 1;
	step = 1.0 * (double)rcs->texts[4].height / (double)spr_h;
	text_p = (double)(start - rcs->res_h / 2) * step;
	while (start < end)
	{
		rcs->spr->spr_y = (int)text_p & (rcs->texts[4].height - 1);
		text_p += step;
		color = get_pixel(&rcs->texts[4], rcs->spr->spr_x, rcs->spr->spr_y);
		if (color >= 0)
			insert_pixel(data, x, start, color);
		start++;
	}
	//printf("sprh:%d\n", spr_h);
	return (rcs);
}
