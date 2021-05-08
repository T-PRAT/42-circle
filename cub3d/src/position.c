/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:47:52 by tprat             #+#    #+#             */
/*   Updated: 2021/05/07 09:25:47 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	key_press(int keycode, t_data *data)
{
	t_key	*key;

	key = data->rcs->key;
	if (keycode == ESC)
		clean_exit(data);
	else if (keycode == FORWARD)
		key->forward = true;
	else if (keycode == BACKWARD)
		key->backward = true;
	else if (keycode == RIGHT)
		key->right = true;
	else if (keycode == LEFT)
		key->left = true;
	else if (keycode == ROT_RIGHT)
		key->rot_right = true;
	else if (keycode == ROT_LEFT)
		key->rot_left = true;
	return (0);
}

int	key_release(int	keycode, t_key	*key)
{
	if (keycode == FORWARD)
		key->forward = false;
	else if (keycode == BACKWARD)
		key->backward = false;
	else if (keycode == RIGHT)
		key->right = false;
	else if (keycode == LEFT)
		key->left = false;
	else if (keycode == ROT_RIGHT)
		key->rot_right = false;
	else if (keycode == ROT_LEFT)
		key->rot_left = false;
	return (0);
}

void	get_dir(t_rcs *rcs, char c)
{
	rcs->dir_x = 0;
	rcs->dir_y = 0;
	rcs->pla_x = 0;
	rcs->pla_y = 0;
	if (c == 'N')
	{
		rcs->dir_y = 1;
		rcs->pla_x = (double)POV / 100;
	}
	if (c == 'S')
	{
		rcs->dir_y = -1;
		rcs->pla_x = (double) - POV / 100;
	}
	if (c == 'E')
	{
		rcs->dir_x = 1;
		rcs->pla_y = (double) - POV / 100;
	}
	if (c == 'W')
	{
		rcs->dir_x = -1;
		rcs->pla_y = (double)POV / 100;
	}
}

t_rcs	*init_key(t_rcs *rcs)
{
	t_key	*key;

	key = malloc (sizeof(t_key));
	if (!key)
		return (0);
	rcs->key = key;
	key->forward = false;
	key->backward = false;
	key->right = false;
	key->left = false;
	key->rot_right = false;
	key->rot_left = false;
	return (rcs);
}

void	get_pos(t_rcs *rcs)
{
	int		i;

	i = 0;
	rcs = init_key(rcs);
	rcs->pos_x = 0;
	rcs->pos_y = 0;
	while (rcs->map[++i])
		;
	i--;
	while (!(ft_strchr("EWSN", rcs->map[i])))
	{
		if (rcs->map[i] == '\n')
			rcs->pos_y++;
		i--;
	}
	get_dir(rcs, rcs->map[i]);
	while (rcs->map[i - 1] != '\n' && i > 1)
	{
		rcs->pos_x += 1.0;
		i--;
	}
}
