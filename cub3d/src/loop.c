/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 18:32:52 by tprat             #+#    #+#             */
/*   Updated: 2021/03/19 16:15:51 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_map	*img_path_to_adr(t_map *map, t_data *data)
{
	if(!(map->texts[0].img = mlx_xpm_file_to_image(data->mlx, map->texts[0].path, \
	&map->texts[0].width, &map->texts[0].height)))
		ft_error("corrupted XPM");
	map->texts[0].addr = (int *)mlx_get_data_addr(map->texts[0].img, &map->texts[0].bpp, &map->texts[0].line_s, &map->texts[0].endian);
	if(!(map->texts[1].img = mlx_xpm_file_to_image(data->mlx, map->texts[1].path, \
	&map->texts[1].width, &map->texts[1].height)))
		ft_error("corrupted XPM");
	map->texts[1].addr = (int *)mlx_get_data_addr(map->texts[1].img, &map->texts[1].bpp, &map->texts[1].line_s, &map->texts[1].endian);
	if(!(map->texts[2].img = mlx_xpm_file_to_image(data->mlx, map->texts[2].path, \
	&map->texts[2].width, &map->texts[2].height)))
		ft_error("corrupted XPM");
	map->texts[2].addr = (int *)mlx_get_data_addr(map->texts[2].img, &map->texts[2].bpp, &map->texts[2].line_s, &map->texts[2].endian);
	if(!(map->texts[3].img = mlx_xpm_file_to_image(data->mlx, map->texts[3].path, \
	&map->texts[3].width, &map->texts[3].height)))
		ft_error("corrupted XPM");
	map->texts[3].addr = (int *)mlx_get_data_addr(map->texts[3].img, &map->texts[3].bpp, &map->texts[3].line_s, &map->texts[3].endian);
	return (map);
}

int		clean_exit(t_data	*data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	free(data->map->key);
	free(data->map);
	free(data);
	exit(1);
	return (0);
}

int		loop(t_map *map)
{
    t_data	*data;
	void	*img;

	if(!(data = malloc (sizeof(t_data))))
		return (0);
	data->map = map;
    data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, map->res_w, map->res_h, "CUB3D");
	map = img_path_to_adr(map, data);
	map = get_pos(map);
	printf("x:%f///y:%f\n", map->pos_x, map->pos_y);
	//printf("dir:%f///%f\n", map->dir_x, map->dir_y);
	//printf("pla:%f///%f\n", map->pla_x, map->pla_y);
	data->img = mlx_new_image(data->mlx, map->res_w, map->res_h);
	data->img_adr = mlx_get_data_addr(data->img, &data->bpp, &data->line_s, &data->endian);
	//map = raycasting(map, data);
	//mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	//mlx_put_image_to_window(data->mlx, data->win, map->texts[3].img, 0, 0);
	mlx_hook(data->win, 17, 0, clean_exit, data);
	mlx_hook(data->win, 2, 1L << 0, key_press, data);
	mlx_loop_hook(data->mlx, raycasting, data);
	mlx_hook(data->win, 3, 1L << 1, key_release, map->key);
	//mlx_key_hook(data->win, deal_key, data);
	mlx_loop(data->mlx);
	//map->img_data = draw_pixel(map->img_data, 1, 1, "255,0,0");
	//printf("%s", map->img_data);
	return (0);
}
