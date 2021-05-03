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
	void	*img;
	t_tex	*texts;

	if(!(map->texts[0].img = mlx_xpm_file_to_image(data->mlx, map->texts[0].path, \
	&map->texts[0].width, &map->texts[0].height)))
		ft_error("corrupted XPM");
	map->texts[0].addr = (int *)mlx_get_data_addr(map->texts[0].img, &map->texts[0].bpp, &map->texts[0].line_s, &map->texts[0].endian);
	if(!(map->texts[1].img = mlx_xpm_file_to_image(data->mlx, map->texts[1].path, \
	&map->texts[1].width, &map->texts[1].height)))
		ft_error("corrupted XPM");
	map->texts[1].addr = (int *)mlx_get_data_addr(map->texts[1].img, &map->texts[1].bpp, &map->texts[1].line_s, &map->texts[1].endian);
	if(!(map->texts[2].img = mlx_xpm_file_to_image(data->mlx, map->texts[2].path, \
	&map->texts[1].width, &map->texts[2].height)))
		ft_error("corrupted XPM");
	map->texts[2].addr = (int *)mlx_get_data_addr(map->texts[2].img, &map->texts[2].bpp, &map->texts[2].line_s, &map->texts[2].endian);
	if(!(map->texts[3].img = mlx_xpm_file_to_image(data->mlx, map->texts[2].path, \
	&map->texts[3].width, &map->texts[3].height)))
		ft_error("corrupted XPM");
	map->texts[3].addr = (int *)mlx_get_data_addr(map->texts[3].img, &map->texts[3].bpp, &map->texts[3].line_s, &map->texts[3].endian);
	return (map);
}

t_data	*new_frame(t_data *data, t_map *map)
{
	void	*img;

	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, map->res_w, map->res_h);
	data->map = raycasting(data->map, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (data);
}

int		deal_key(int key, t_data *data)
{
	//ft_putnbr_fd(key, 1);
	if (key == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(1);
	}
	else if (key == 13 && check_wall((int)data->map->pos_x + 0.1, \
	(int)data->map->pos_y, data->map) == 1 )
	{
		data->map->pos_y += 0.1;
		data = new_frame(data, data->map);
	}
	else if (key == 0 && check_wall((int)data->map->pos_x - 0.1, \
	(int)data->map->pos_y, data->map) == 1)
	{
		data->map->pos_x -= 0.1;
		data = new_frame(data, data->map);
	}
	else if (key == 1 && check_wall((int)data->map->pos_x, \
	(int)data->map->pos_y - 0.1, data->map) == 1)
	{
		data->map->pos_y -= 0.1;
		data = new_frame(data, data->map);
	}
	else if (key == 2 && check_wall((int)data->map->pos_x, \
	(int)data->map->pos_y + 0.1, data->map) == 1)
	{
		data->map->pos_x += 0.1;
		data = new_frame(data, data->map);
	}
	return (0);
}

int	loop(t_map *map)
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
	printf("pos:%f///%f\n", map->pos_x, map->pos_y);
	//printf("dir:%f///%f\n", map->dir_x, map->dir_y);
	//printf("pla:%f///%f\n", map->pla_x, map->pla_y);
	data->img = mlx_new_image(data->mlx, map->res_w, map->res_h);
	data->img_adr = mlx_get_data_addr(data->img, &data->bpp, &data->line_s, &data->endian);
	map = raycasting(map, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, map->texts[0].img, 0, 0);
	mlx_key_hook(data->win, deal_key, data);
	mlx_loop(data->mlx);
	//map->img_data = draw_pixel(map->img_data, 1, 1, "255,0,0");
	//printf("%s", map->img_data);
	return (0);
}
