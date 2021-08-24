/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:42:28 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/06/28 20:36:49 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	goto_endofline(t_curs_pos *cursor, char *line)
{
	int	size;

	size = ft_strlen(line);
	while ((int)cursor->line_pos < size)
		key_left_right(line, ARROW_RIGHT, cursor);
}

char	*ret_exit(void)
{
	write(1, "\n", 1);
	return (ft_strdup("exit"));
}

char 	*read_buffer(int *buffer, char *line, t_curs_pos *curs, t_history **h)
{
	int	ret;

	if (!line)
		return (NULL);
	*buffer = 0;
	ret = read(0, buffer, 4);
	if (ret < 0)
		return (NULL);
	if (g_sigint)
	{
		free(line);
		line = ft_strdup("");
		(*h)->line = line;
		curs->line_pos = 0;
		g_sigint = false;
	}
	return (line);
}

char	*read_loop(t_curs_pos curs, char *line, t_history **hist, int *buffer)
{
	t_history	*curr_hist;

	curr_hist = *hist;
	while (*buffer != '\n')
	{
		line = read_buffer(buffer, line, &curs, hist);
		if (!line)
			return (NULL);
		else if (*buffer == CTRL_D)
			return (ret_exit());
		else if (*buffer == DEL_RIGHT)
			line = delete_right(line, &curs);
		else if (*buffer >= 4283163 || *buffer == KEY_DLE)
			line = arrow_keys(line, *buffer, &curs, &curr_hist);
		else if (*buffer == DEL_LEFT)
			line = delete_left(line, &curs);
		else if (*buffer > 31 && *buffer < 127 && *buffer != '\n')
			line = add_char(line, *buffer, &curs);
		(*hist)->line = line;
	}
	if ((!ft_strncmp(line, "exit", 4) && ft_strlen(line) == 4)
		|| !ft_strncmp(line, "exit ", 5))
		return (ft_strdup(line));
	return (line);
}

char	*get_line(int path_size, t_history **history)
{
	t_curs_pos	cursor;
	char		*line;
	int			buffer;

	buffer = 0;
	cursor.line_pos = 0;
	cursor.path_size = path_size;
	line = ft_strdup("");
	*history = history_add_link(*history, line);
	if (!*history)
		return (NULL);
	line = read_loop(cursor, line, history, &buffer);
	if (!line)
		return (NULL);
	goto_endofline(&cursor, line);
	write(1, &buffer, 1);
	if (!ft_strlen(line))
		*history = history_del_first_link(*history);
	return (line);
}
