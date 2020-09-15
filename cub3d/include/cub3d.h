/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 17:00:29 by user42            #+#    #+#             */
/*   Updated: 2020/09/14 22:52:42 by tprat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
// A VIRER
# include <stdio.h>
# include "../libft/libft.h"

typedef struct  s_vars {
	void    *mlx;
    void    *win;

}               t_vars;

typedef struct s_map
{
	char	*map;
	int		res_w;
	int		res_h;
	char	*text_N;
	char	*text_S;
	char	*text_W;
	char	*text_E;
	char	*sprite;
	char	*color_f;
	char	*color_c;
}				t_map;

t_map	*parse_map(char *map_path);

#endif
