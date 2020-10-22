/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 01:39:15 by tprat             #+#    #+#             */
/*   Updated: 2020/10/14 21:25:33 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	*create_image(t_loop *loop, t_map *map)
{
	void	*img;
	void	*text_N;
	char	*addr;
	int		bpp = 32;
	int		endian = 0;
	int		larg;
	int		s_line = 360;

	img = mlx_new_image(loop->mlx, map->res_w, map->res_h);
	text_N = mlx_xpm_file_to_image(loop->mlx, map->text_N, &larg, &larg);
	addr = mlx_get_data_addr(text_N, &bpp, &s_line, &endian);
    ft_memcpy(addr, "\0\0\0\0\0\0\0\0\0", 9);
	write(1, text_N, 10);
}