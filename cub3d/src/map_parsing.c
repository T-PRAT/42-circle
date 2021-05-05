/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 16:21:22 by tprat             #+#    #+#             */
/*   Updated: 2021/05/05 17:30:23 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_rcs	*get_line_info2(t_rcs *rcs, char **parts)
{
	if (!(ft_strncmp(parts[0], "NO", 3)))
		rcs->texts[0].path = ft_strdup(parts[1]);
	else if (!(ft_strncmp(parts[0], "SO", 3)))
		rcs->texts[1].path = ft_strdup(parts[1]);
	else if (!(ft_strncmp(parts[0], "WE", 3)))
		rcs->texts[2].path = ft_strdup(parts[1]);
	else if (!(ft_strncmp(parts[0], "EA", 3)))
		rcs->texts[3].path = ft_strdup(parts[1]);
	else if (!(ft_strncmp(parts[0], "S", 2)))
		rcs->texts[4].path = ft_strdup(parts[1]);
	else if (!(ft_strncmp(parts[0], "F", 2)))
		rcs->color_f = get_color(parts[1]);
	else if (!(ft_strncmp(parts[0], "C", 2)))
		rcs->color_c = get_color(parts[1]);
	else
		return (0);
	return (rcs);
}

void	free_2d_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

t_rcs	*get_line_info(t_rcs *rcs, char *line)
{
	char	**parts;
	int		i;

	i = 0;
	parts = ft_split(line, ' ');
	while (parts[i] != 0)
		i++;
	if (i == 3)
	{
		if (parts[0][0] != 'R' || parts[0][1] != 0)
			return (0);
		rcs->res_w = ft_atoi(parts[1]);
		rcs->res_h = ft_atoi(parts[2]);
	}
	else if (i == 2)
	{
		rcs = get_line_info2(rcs, parts);
		if (!rcs)
			return (0);
	}
	else
		return (0);
	free_2d_str(parts);
	return (rcs);
}

t_rcs	*get_rcs(t_rcs *rcs, char *line, int fd)
{
	int		c;
	char	*tmp;

	c = 1;
	rcs->map = ft_strdup("");
	while (c)
	{
		tmp = rcs->map;
		rcs->map = ft_strjoin(rcs->map, line);
		rcs->map = ft_strjoin(rcs->map, "\n");
		free(tmp);
		c = get_next_line(fd, &line);
	}
	rcs->map = ft_strjoin(rcs->map, line);
	rcs->map = clean_map(rcs->map);
	if (!rcs->map)
		return (0);
	return (rcs);
}

t_rcs	*parse_map(t_rcs *rcs, char *map_path)
{
	int		fd;
	char	*line;
	int		c;

	c = 1;
	fd = open(map_path, O_RDONLY);
	while (c)
	{
		c = get_next_line(fd, &line);
		if (line[0] && line[0] != '1')
			rcs = get_line_info(rcs, line);
		else if (line[0] == '1')
		{
			rcs = get_rcs(rcs, line, fd);
			if (!rcs)
				return (0);
			c = 0;
		}
	}
	return (rcs);
}
