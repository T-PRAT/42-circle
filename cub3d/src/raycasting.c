/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 00:28:07 by tprat             #+#    #+#             */
/*   Updated: 2021/05/06 15:33:19 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	new_sprite_list(t_rcs *rcs)
{
	t_spr	*new;
	t_spr	*current;


	new = (t_spr *)malloc(sizeof(t_spr));
	if (!new)
		ft_error("malloc struc du spite impossible");
	new->next = 0;
	new->spr_pos_x = rcs->map_x;
	new->spr_pos_y = rcs->map_y;
	if (rcs->spr == 0)
		rcs->spr = &new;
	current = rcs->spr[0];
	while (current->next)
	{
		current = current->next;
	}
	current->next = new;
}

t_rcs	*ray_steps(t_rcs *rcs)
{
	t_spr	*current;

	while (is_wall(rcs->map_x, rcs->map_y, rcs))
	{
		if (rcs->side_x < rcs->side_y)
		{
			rcs->side_x += rcs->delta_x;
			rcs->map_x += rcs->step_x;
			rcs->side = 0;
		}
		else
		{
			rcs->side_y += rcs->delta_y;
			rcs->map_y += rcs->step_y;
			rcs->side = 1;
		}
		if (is_wall(rcs->map_x, rcs->map_y, rcs) == 2)
		{
			if (rcs->spr == NULL)
				new_sprite_list(rcs);
			else
			{
				current = *rcs->spr;
				write(1, "a", 1);
				while (current->next && current)
					current = current->next;
				if (current->spr_pos_x != rcs->map_x || current->spr_pos_y != rcs->map_y)
					new_sprite_list(rcs);
			}
		}
	}
	return (rcs);
}

t_rcs	*ray_steps_init(t_rcs *rcs)
{
	if (rcs->ray_x < 0)
	{
		rcs->step_x = -1;
		rcs->side_x = (rcs->pos_x - (double)rcs->map_x) * rcs->delta_x;
	}
	else
	{
		rcs->step_x = 1;
		rcs->side_x = ((double)rcs->map_x + 1 - rcs->pos_x) * rcs->delta_x;
	}
	if (rcs->ray_y < 0)
	{
		rcs->step_y = -1;
		rcs->side_y = (rcs->pos_y - (double)rcs->map_y) * rcs->delta_y;
	}
	else
	{
		rcs->step_y = 1;
		rcs->side_y = ((double)rcs->map_y + 1 - rcs->pos_y) * rcs->delta_y;
	}
	return (ray_steps(rcs));
}

void	start_raycast(t_rcs *rcs, t_data *data)
{
	int	x;

	x = 0;
	while (x < rcs->res_w)
	{
		rcs->cam_x = 2 * x / (double)(rcs->res_w) - 1;
		rcs->ray_x = rcs->dir_x + rcs->pla_x * rcs->cam_x;
		rcs->ray_y = rcs->dir_y + rcs->pla_y * rcs->cam_x;
		rcs->map_x = (int)rcs->pos_x;
		rcs->map_y = (int)rcs->pos_y;
		if (rcs->ray_y == 0)
			rcs->delta_x = 0;
		else
		{
			if (rcs->ray_x == 0)
				rcs->delta_x = 1;
			else
				rcs->delta_x = fabs(1 / rcs->ray_x);
		}
		if (rcs->ray_x == 0)
			rcs->delta_y = 0;
		else
		{
			if (rcs->ray_y == 0)
				rcs->delta_y = 1;
			else
				rcs->delta_y = fabs(1 / rcs->ray_y);
		}
		rcs = ray_steps_init(rcs);
		draw_line(rcs, data, x);
		x++;
	}
}

int	raycasting(t_data *data)
{
	start_raycast(data->rcs, data);
	select_sprite(data->rcs, data);
	if (data->rcs->save == true)
		return (1);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	check_move(data->rcs);
	return (1);
}
