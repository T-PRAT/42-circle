/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 16:51:16 by tprat             #+#    #+#             */
/*   Updated: 2021/05/07 08:51:15y tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	get_color(char *str)
{
	int	r;
	int	g;
	int	b;
	int	i;

	i = 0;
	r = ft_atoi(str);
	while (str[i++] != ',')
		;
	g = ft_atoi(str + i);
	while (str[i++] != ',')
		;
	b = ft_atoi(str + i);
	return (0 << 24 | r << 16 | g << 8 | b);
}

int 	check_body(char *map, int i)
{
	int	P;

	P = 0;
	while (map[i])
	{
		if (map[i] != '1')
			return (0);
		while (map[i] != '\n' && map[i + 1])
		{
			if (ft_strchr("NSEW", map[i]))
				P++;
			else if (!(ft_strchr("012", map[i])))
				return (0);
			i++;
		}
		if (map[i - 1] != '1')
			return (0);
		i++;
	}
	if (P != 1)
		return (0);
	return (i);
}

int	check_map(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\n' && map[i])
	{
		if (map[i++] != '1')
			return (0);
	}
	i++;
	i = check_body(map, i);
	if (!i)
		return (0);
	i -= 2;
	while (map[i] != '\n')
	{
		if (map[i--] != '1')
			return (0);
	}
	return (1);
}

void	clean_map2(t_rcs *rcs, int i, int c)
{
	char	*clean_map;

	clean_map = malloc(sizeof(char) * c);
	if (!clean_map)
		ft_error("map invalide");
	c--;
	clean_map[c] = '\0';
	c--;
	i -= 2;
	while (i >= 0)
	{
		if (ft_strchr("012NSEW\n", rcs->map[i]))
			clean_map[c--] = rcs->map[i];
		i--;
	}
	free(rcs->map);
	if (!(check_map(clean_map)))
	{
		free (clean_map);
		ft_error("map invalide");
	}
	rcs->map = clean_map;
}

void	clean_map(t_rcs *rcs)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (rcs->map[i])
	{
		if (!(ft_strchr("012NSEW \n", rcs->map[i])))
			ft_error("map invalide");
		if (ft_strchr("012NSEW\n", rcs->map[i]))
			c++;
		i++;
	}
	clean_map2(rcs, i, c);
}
