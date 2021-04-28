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

int	close_wd(int keycode, t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	return (0);
}

t_map	*img_path_to_adr(t_map *map, t_data *data)
{
	void	*img;

	map->texts = malloc(sizeof(map->texts));
	img = mlx_xpm_file_to_image(data->mlx, map->text_N, \
	&data->line_s, &data->line_s);
	map->texts[0] = mlx_get_data_addr(img, &data->bpp, \
	&data->line_s, &data->endian);
	img = mlx_xpm_file_to_image(data->mlx, map->text_S, \
	&data->line_s, &data->line_s);
	map->texts[1] = mlx_get_data_addr(img, &data->bpp, \
	&data->line_s, &data->endian);
	img = mlx_xpm_file_to_image(data->mlx, map->text_E, \
	&data->line_s, &data->line_s);
	map->texts[2] = mlx_get_data_addr(img, &data->bpp, \
	&data->line_s, &data->endian);
	img = mlx_xpm_file_to_image(data->mlx, map->text_W, \
	&data->line_s, &data->line_s);
	map->texts[3] = mlx_get_data_addr(img, &data->bpp, \
	&data->line_s, &data->endian);
	map->texts[4] = ft_strdup(0);
	return (map);
}

int	deal_key(int key, t_data *data)
{
	//ft_putnbr_fd(key, 1);
	if (key == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit (0);
		return (0);
	}
	if (key == 13 && check_wall((int)data->map->pos_x + 0.1, \
	(int)data->map->pos_y, data->map) == 1 )
		data->map->pos_y += 0.1;
	if (key == 0 && check_wall((int)data->map->pos_x - 0.1, \
	(int)data->map->pos_y, data->map) == 1)
		data->map->pos_x -= 0.1;
	if (key == 1 && check_wall((int)data->map->pos_x, \
	 (int)data->map->pos_y - 0.1, data->map) == 1)
		data->map->pos_y -= 0.1;
	if (key == 2 && check_wall((int)data->map->pos_x, \
	 (int)data->map->pos_y + 0.1, data->map) == 1)
		data->map->pos_x += 0.1;
	data->map = raycasting(data->map, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

int	loop(t_map *map)
{
    t_data	*data;
	void	*img;
	int		color;

	if(!(data = malloc (sizeof(t_data))))
		return (0);
	data->map = map;
    data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, map->res_w, map->res_h, "CUB3D");
	map = img_path_to_adr(map, data);
	map = get_pos(map);
	printf("pos:%f///%f\n", map->pos_x, map->pos_y);
	//printf("dir:%f///%f\n", map->dir_x, map->dir_y);
	//printf("pla:%f///%f\n", map->pla_x, map->pla_y);
	data->img = mlx_new_image(data->mlx, map->res_w, map->res_h);
	data->img_adr = mlx_get_data_addr(data->img, &data->bpp, &data->line_s, &data->endian);
	map = raycasting(map, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_key_hook(data->win, deal_key, data);
	mlx_loop(data->mlx);
	//map->img_data = draw_pixel(map->img_data, 1, 1, "255,0,0");
	//printf("%s", map->img_data);
	return (0);
}
