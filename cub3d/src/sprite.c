/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 10:43:24 by tprat             #+#    #+#             */
/*   Updated: 2021/05/07 16:45:10 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	swap_struct(t_rcs *rcs, int c)
{
	t_spr	*tmp;
	t_spr	*curr;

	while (c >= 0)
	{
		curr = rcs->spr;
		while (curr && curr->next)
		{
			if (curr->perp_d < curr->next->perp_d)
			{
				tmp = curr->next->next;
				curr->next = curr->next->next;
				tmp = curr;
			}
			curr = curr->next;
		}
		c--;
	}
}

void	sprite_dist(t_rcs *rcs)
{
	t_spr	*curr;
	int		c;

	c = 0;
	curr = rcs->spr;
	while (curr)
	{
		curr->perp_d = ((rcs->pos_x - curr->spr_pos_x) * (rcs->pos_x - \
		curr->spr_pos_x) + (rcs->pos_y - curr->spr_pos_y) * \
		(rcs->pos_y - curr->spr_pos_y));
		curr = curr->next;
		c++;
	}
	swap_struct(rcs, c);
}

void	sprite_calc(t_rcs *rcs, t_spr *spr)
{
	double	spr_x;
	double	spr_y;
	double	face;

	spr_x = spr->spr_pos_x - rcs->pos_x;
	spr_y = spr->spr_pos_y - rcs->pos_y;
	face = 1.0 / (rcs->pla_x * rcs->dir_y - rcs->dir_x * rcs->pla_y);
	spr->trans_x = face * (rcs->dir_y * spr_x - rcs->dir_x * spr_y);
	spr->trans_y = face * (-rcs->pla_y * spr_x + rcs->pla_x * spr_y);
	spr->spr_t = (int)((rcs->res_w / 2) * (1 + spr->trans_x / spr->trans_y));
	spr->spr_h = abs((int)(rcs->res_h / spr->trans_y));
	spr->start_y = -spr->spr_h / 2 + rcs->res_h / 2;
	if (spr->start_y < 0)
		spr->start_y = 0;
	spr->end_y = spr->spr_h / 2 + rcs->res_h / 2;
	if (spr->end_y >= rcs->res_h)
		spr->end_y = rcs->res_h - 1;
	spr->spr_w = abs((int)(rcs->res_h / spr->trans_y));
	spr->start_x = -spr->spr_w / 2 + spr->spr_t;
	if (spr->start_x < 0)
		spr->start_x = 0;
	spr->end_x = (spr->spr_w / 2) + spr->spr_t;
	if (spr->end_x >= rcs->res_w)
		spr->end_x = rcs->res_w - 1;
}

void	draw_sprite(t_rcs *rcs, t_data *data, t_spr *spr)
{
	int		tex_x;
	int		tex_y;
	int		y;

	sprite_calc(rcs, spr);
	while (spr->start_x < spr->end_x)
	{
		tex_x = (256 * (spr->start_x - (-spr->spr_w / 2 + spr->spr_t)) * \
		rcs->texts[4].width / spr->spr_w) / 256;
		if (spr->trans_y > 0 && spr->start_x > 0 && spr->start_x < \
		rcs->res_w && spr->trans_y < rcs->perp_ds[spr->start_x])
		{
			y = spr->start_y;
			while (y < spr->end_y)
			{
				tex_y = (((y * 256 - rcs->res_h * 128 + spr->spr_h * 128) \
				* rcs->texts[4].height) / spr->spr_h) / 256;
				if (get_pixel(&rcs->texts[4], tex_x, tex_y) > 0)
					insert_pixel(data, spr->start_x, y, get_pixel(&rcs->texts[4], \
					tex_x, tex_y));
				y++;
			}
		}
		spr->start_x++;
	}
}

void	select_sprite(t_rcs *rcs, t_data *data)
{
	t_spr	*tmp;

	tmp = NULL;
	sprite_dist(rcs);
	tmp = rcs->spr;
	while (tmp)
	{
		draw_sprite(rcs, data, tmp);
		tmp = tmp->next;
	}
	while (rcs->spr)
	{
		tmp = rcs->spr;
		rcs->spr = rcs->spr->next;
		free(tmp);
	}
	rcs->spr = NULL;
}
