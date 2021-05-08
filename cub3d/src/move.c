/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:33:10 by tprat             #+#    #+#             */
/*   Updated: 2021/05/07 16:53:04 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_move3(t_rcs *rcs)
{
	double	old_dir_x;
	double	old_pla_x;

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
	check_move3(rcs);
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

t_rcs	*new_sprite_list(t_rcs *rcs)
{
	t_spr	*new;
	t_spr	*current;

	current = NULL;
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
	return (rcs);
}
