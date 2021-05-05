/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 18:32:52 by tprat             #+#    #+#             */
/*   Updated: 2021/05/05 17:59:38 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_rcs	*img_path_to_adr(t_rcs *rcs, t_data *data)
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
	return (rcs);
}

int	clean_exit(t_data	*data)
{
	mlx_destroy_image(data->mlx, data->rcs->texts[0].img);
	mlx_destroy_image(data->mlx, data->rcs->texts[1].img);
	mlx_destroy_image(data->mlx, data->rcs->texts[2].img);
	mlx_destroy_image(data->mlx, data->rcs->texts[3].img);
	mlx_destroy_image(data->mlx, data->rcs->texts[4].img);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	free(data->rcs->perp_ds);
	free(data->rcs->key);
	free(data->rcs);
	free(data);
	exit(1);
	return (0);
}

int	loop(t_rcs *rcs)
{
    t_data	*data;

	if(!(data = malloc (sizeof(t_data))))
		return (0);
	if(!(rcs->perp_ds = malloc (sizeof(double) * (rcs->res_w + 1))))
		return (0);
	if(!(rcs->spr = malloc (sizeof(t_spr))))
		return (0);
	data->rcs = rcs;
    data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, rcs->res_w, rcs->res_h, "CUB3D");
	rcs = img_path_to_adr(rcs, data);
	rcs = get_pos(rcs);
	printf("x:%f///y:%f\n", rcs->pos_x, rcs->pos_y);
	//printf("dir:%f///%f\n", rcs->dir_x, rcs->dir_y);
	//printf("pla:%f///%f\n", rcs->pla_x, rcs->pla_y);
	data->img = mlx_new_image(data->mlx, rcs->res_w, rcs->res_h);
	data->img_adr = mlx_get_data_addr(data->img, &data->bpp, &data->line_s, &data->endian);
	//rcs = raycasting(rcs, data);
	//mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	//mlx_put_image_to_window(data->mlx, data->win, rcs->texts[4].img, 0, 0);
	if (rcs->save == true)
		save_image(data, rcs);
	mlx_hook(data->win, 17, 0, clean_exit, data);
	mlx_hook(data->win, 2, 1L << 0, key_press, data);
	mlx_loop_hook(data->mlx, raycasting, data);
	mlx_hook(data->win, 3, 1L << 1, key_release, rcs->key);
	//mlx_key_hook(data->win, deal_key, data);
	mlx_loop(data->mlx);
	//rcs->img_data = draw_pixel(rcs->img_data, 1, 1, "255,0,0");
	//printf("%s", rcs->img_data);
	return (0);
}
