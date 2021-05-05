/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:47:52 by tprat             #+#    #+#             */
/*   Updated: 2021/05/05 15:10:38 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	key_press(int keycode, t_data *data)
{
	t_key	*key;

	key = data->map->key;
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
	else if(keycode == BACKWARD)
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

t_map	*get_dir(t_map *map, char c)
{
	map->dir_x = 0;
	map->dir_y = 0;
	map->pla_x = 0;
	map->pla_y = 0;
	if (c == 'N')
	{
		map->dir_y = 1;
		map->pla_x = (double)POV / 100;
	}
	if (c == 'S')
	{
		map->dir_y = -1;
		map->pla_x = (double)-POV / 100;
	}
	if (c == 'E')
	{
		map->dir_x = 1;
		map->pla_y = (double)-POV / 100;
	}
	if (c == 'W')
	{
		map->dir_x = -1;
		map->pla_y = (double)POV / 100;
	}
	return (map);
}

t_map	*init_key(t_map *map)
{
	t_key	*key;

	if(!(key = malloc (sizeof(t_key))))
		return (0);
	map->key = key;
	key->forward = false;
	key->backward = false;
	key->right = false;
	key->left = false;
	key->rot_right = false;
	key->rot_left = false;
	return (map);
}

t_map	*get_pos(t_map *map)
{
	int		i;

	i = 0;
	map = init_key(map);
	map->pos_x = 0;
	map->pos_y = 0;
	while (map->map[++i]);
	i--;
	while (!(ft_strchr("EWSN", map->map[i])))
	{
		if (map->map[i] == '\n')
			map->pos_y++;
		i--;
	}
	map = get_dir(map, map->map[i]);
	while (map->map[i - 1] != '\n' && i > 1)
	{
		map->pos_x++;
		i--;
	}
	return (map);
}
