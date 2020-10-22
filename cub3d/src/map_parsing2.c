/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 16:51:16 by tprat             #+#    #+#             */
/*   Updated: 2020/10/22 00:35:04 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int 	check_body(char *map, int i)
{
	int P;

	P = 0;
	while (map[i])
	{
		if (map[i] != '1')
			return (0);
		while (map[i] != '\n' && map[i])
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

int		check_map(char *map)
{
	int i;

	i = 0;
	while (map[i] != '\n' && map[i])
	{
		if (map[i++] != '1')
			return (0);
	}
	i++;
	if (!(i = check_body(map, i)))
		return (0);
	i -= 2;
	while (map[i] != '\n')
	{
		if (map[i--] != '1')
			return (0);
	}
	return (1);
}

char	*clean_map(char *map)
{
	int	i;
	int c;
	char *clean_map;

	i = 0;
	c = 0;
	while (map[i])
	{
		if (!(ft_strchr("012NSEW \n", map[i])))
			return (0);
		if (ft_strchr("012NSEW\n", map[i]))
			c++;
		i++;
	}
	clean_map = malloc(sizeof(char) * c);
	while (i >= 0)
	{
		if (ft_strchr("012NSEW\n", map[i]))
			clean_map[c--] = map[i];
		i--;
	}
	free(map);
	if (!(check_map(clean_map)))
		return (0);
	return (clean_map);
}