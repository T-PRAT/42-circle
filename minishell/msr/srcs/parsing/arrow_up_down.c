/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_up_down.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:01:54 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/06/24 16:47:30 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*del_line(char *line, t_curs_pos *cursor)
{
	goto_endofline(cursor, line);
	while (cursor->line_pos > 0 && line)
		line = delete_left(line, cursor);
	return (line);
}

char	*key_up(char *line, t_curs_pos *curs, t_history **list)
{
	line = del_line(line, curs);
	if (!line)
		return (NULL);
	*list = (*list)->next;
	free(line);
	write(1, (*list)->line, ft_strlen((*list)->line));
	curs->line_pos = ft_strlen((*list)->line);
	return (ft_strdup((*list)->line));
}

char	*key_down(char *line, t_curs_pos *curs, t_history **list)
{
	line = del_line(line, curs);
	if (!line)
		return (NULL);
	*list = (*list)->previous;
	free(line);
	if ((*list)->line)
		write(1, (*list)->line, ft_strlen((*list)->line));
	if ((*list)->line)
		curs->line_pos = ft_strlen((*list)->line);
	return (ft_strdup((*list)->line));
}

char	*key_up_down(char *line, int buff, t_curs_pos *curs, t_history **list)
{
	if ((buff == KEY_DLE || buff == ARROW_UP) && (*list)->next)
		return (key_up(line, curs, list));
	else if (buff == ARROW_DOWN && (*list)->previous
		&& (*list)->previous->previous)
		return (key_down(line, curs, list));
	return (line);
}
