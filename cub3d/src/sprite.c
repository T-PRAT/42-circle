/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 10:43:24 by tprat             #+#    #+#             */
/*   Updated: 2021/05/06 18:15:03 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	new_sprite_list(t_rcs *rcs)
{
	t_spr	*new;
	t_spr	*current;


	new = malloc(sizeof(t_spr));
	if (!new)
		ft_error("malloc struc du spite impossible");
	new->next = NULL;
	new->spr_pos_x = rcs->map_x;
	new->spr_pos_y = rcs->map_y;
	if (rcs->spr == 0)
		rcs->spr = new;
	else
	{
		current = rcs->spr;
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

void	sprite_dist(t_rcs *rcs)
{
	t_spr	*curr;
	t_spr	*tmp;
	int		c;

	curr = rcs->spr;
	while (curr->next)
	{
		curr->perp_d = ((rcs->pos_x - curr->spr_pos_x) * (rcs->pos_x - \
		curr->spr_pos_x) + (rcs->pos_y - curr->spr_pos_y) * \
		(rcs->pos_y - curr->spr_pos_y));
		curr = curr->next;
	}
	while (c)
	{
		curr = rcs->spr;
		while (curr->next)
		{
			if (curr->perp_d < curr->next->perp_d)
			{
				tmp = curr->next->next;
				curr->next->next = curr;
				curr->next = tmp;
			}
			curr = curr->next;
		}
		c--;
	}
}

void	sprite_calc(t_rcs *rcs, t_spr *spr)
{
	double	spr_x;
	double	spr_y;
	double	face;

	spr_x = spr->spr_pos_x - rcs->pos_x;
	spr_y = spr->spr_pos_y - rcs->pos_y;
	face = 1.0 / (rcs->pla_x * rcs->dir_y - rcs->dir_x * rcs->pla_y);
	//printf("sprx:%f||spry:%f\n", spr_x, spr_y);
	spr->trans_x = face * (rcs->dir_y * spr_x - rcs->dir_x * spr_y);
	spr->trans_y = face * (-rcs->pla_y * spr_x + rcs->pla_x * spr_y);
	//printf("trax:%f||tray:%f\n", spr->trans_x, spr->trans_y);
	spr->spr_t = (int)((rcs->res_w / 2) * (1 + spr->trans_x / spr->trans_y));
	spr->spr_h = abs((int)(rcs->res_h / spr->trans_y));
	spr->start_y = -spr->spr_h / 2 + rcs->res_h / 2;
	if (spr->start_y < 0)
		spr->start_y = 0;
	spr->end_y = spr->spr_h / 2 + rcs->res_h / 2;
	if (spr->end_y >= rcs->res_h)
		spr->end_y = rcs->res_h - 1;
	spr->spr_w = abs((int)(rcs->res_h / spr->trans_y));
	//printf("sprw:%d\n", spr->spr_w);
	//printf("sprt:%d\n", spr->spr_t);
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
	int		color;

	sprite_calc(rcs, spr);
	//printf("res_h:%d||res_w%d\n", rcs->res_h, rcs->res_w);
	//printf("start_y:%d||end_y:%d\n", spr->start_y, spr->end_y);
	//printf("start_x:%d||end_x:%d\n", spr->start_x, spr->end_x);
	while (spr->start_x < spr->end_x)
	{
		tex_x = (256 * (spr->start_x - (-spr->spr_w / 2 + spr->spr_t)) * rcs->texts[4].width / spr->spr_w) / 256;
		if (spr->trans_y > 0 && spr->start_x > 0 && spr->start_x < rcs->res_w && spr->trans_y < rcs->perp_ds[spr->start_x])
		{
			y = spr->start_y;
			while (y < spr->end_y)
			{
				tex_y = (((y * 256 - rcs->res_h * 128 + spr->spr_h * 128) * rcs->texts[4].height) / spr->spr_h) / 256;
				//printf("texx:%d||texy:%d\n", tex_x, tex_y);
				color = get_pixel(&rcs->texts[4], tex_x, tex_y);
				if (color >= 0)
					insert_pixel(data, spr->start_x, y, color);
				y++;
			}
		}
		spr->start_x++;
	}
}

void	select_sprite(t_rcs *rcs, t_data *data)
{
	t_spr	*tmp;

	sprite_dist(rcs);
	tmp = rcs->spr;
	while (tmp->next)
	{
		//printf("perp_d%f\n", tmp->perp_d);
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
