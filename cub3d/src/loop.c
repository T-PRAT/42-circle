/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 18:32:52 by tprat             #+#    #+#             */
/*   Updated: 2021/05/08 09:04:18 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_screen_size(t_data *data, t_rcs *rcs)
{
	int	width;
	int	height;

	mlx_get_screen_size(data->mlx, &width, &height);
	if (rcs->res_w > width)
		rcs->res_w = width;
	if (rcs->res_h > height)
		rcs->res_h = height;
}

void	img_path_to_adr(t_rcs *rcs, t_data *data)
{
	int	x;

	x = 0;
	while (x < 5)
	{
		rcs->texts[x].img = mlx_xpm_file_to_image(data->mlx, rcs->texts[x].path, \
		&rcs->texts[x].width, &rcs->texts[x].height);
		if (!rcs->texts[x].img)
			ft_error(".xpm corrompu");
		rcs->texts[x].addr = (int *)mlx_get_data_addr(rcs->texts[x].img, \
		&rcs->texts[x].bpp, &rcs->texts[x].line_s, &rcs->texts[x].endian);
		x++;
	}
}

void	init_all(t_data *data, t_rcs *rcs)
{
	data->rcs = rcs;
	data->win = NULL;
	data->img = NULL;
	rcs->spr = NULL;
	data->rcs->perp_ds = NULL;
}

int	clean_exit(t_data	*data)
{
	int	i;

	i = 0;
	while (i <= 4)
	{
		if (data->rcs->texts[i].img)
			mlx_destroy_image(data->mlx, data->rcs->texts[i].img);
		i++;
	}
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->rcs->perp_ds)
		free(data->rcs->perp_ds);
	if (data->rcs->key)
		free(data->rcs->key);
	if (data->rcs)
		free(data->rcs);
	free(data);
	exit(0);
	return (0);
}

int	loop(t_rcs *rcs)
{
	t_data	*data;

	data = malloc (sizeof(t_data));
	if (!data)
		return (0);
	data->mlx = mlx_init();
	init_all(data, rcs);
	rcs->perp_ds = malloc (sizeof(double) * (rcs->res_w + 1));
	if (!rcs->perp_ds)
		return (0);
	check_screen_size(data, rcs);
	img_path_to_adr(rcs, data);
	get_pos(rcs);
	if (rcs->save == true)
		save_image(data, rcs);
	data->win = mlx_new_window(data->mlx, rcs->res_w, rcs->res_h, "CUB3D");
	mlx_hook(data->win, 17, 0, clean_exit, data);
	mlx_hook(data->win, 2, 1L << 0, key_press, data);
	mlx_loop_hook(data->mlx, raycasting, data);
	mlx_hook(data->win, 3, 1L << 1, key_release, rcs->key);
	mlx_loop(data->mlx);
	return (0);
}
