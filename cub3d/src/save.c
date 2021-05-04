/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:58:57 by tprat             #+#    #+#             */
/*   Updated: 2021/05/04 18:04:40 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	save_image(t_map *map)
{
	int	fd;

	if (!(fd = open("cub3d.bmp", O_CREAT | O_RDWR)))
		ft_error("Erreur lors de la création du .bmp\n");

}
