/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 17:00:29 by user42            #+#    #+#             */
/*   Updated: 2021/03/05 13:05:19 by tprat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//# include "../mlx/mlx.h"
# include "../mlx-linux/mlx.h"
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
// A VIRER
# include <stdio.h>
# include "../libft/libft.h"

# define UNIT 64
# define POV 60

typedef struct  s_loop {
	void    *mlx;
    void    *win;
}               t_loop;

typedef struct s_map
{
	char	*map;
	int		res_w;
	int		res_h;
	char	*text_N;
	char	*text_S;
	char	*text_W;
	char	*text_E;
	char	**all_text;
	char	*sprite;
	char	*color_f;
	char	*color_c;
	double	dir_x;
	double	dir_y;
	double	pos_x;
	double	pos_y;
	double	pla_x;
	double	pla_y;
	double	ray_x;
	double	ray_y;
	double	cam_x;
	double	side_x;
	double	side_y;
	double	delta_x;
	double	delta_y;
	double	ray_l;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
	char	side;
}				t_map;

t_map	*parse_map(char *map_path);
char	*clean_map(char *map);
int		loop(t_map *map);
void	*create_image(t_loop *loop, t_map *map);
t_map	*get_pos(t_map *map);
t_map	*raycasting(t_map *map, t_loop *loop);

#endif
