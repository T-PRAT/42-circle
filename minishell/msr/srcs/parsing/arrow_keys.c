/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:58:08 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/06/28 20:35:44 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	key_left_right(char *line, int buffer, t_curs_pos *cursor)
{
	struct winsize	win;

	ioctl(1, TIOCGWINSZ, &win);
	if (buffer == ARROW_LEFT && cursor->line_pos > 0)
	{
		if ((cursor->path_size + cursor->line_pos) % win.ws_col > 0)
			ft_printf("%s", tgetstr("le", NULL));
		else
			ft_printf("%s%s", tgetstr("up", NULL),
				tgoto(tgetstr("ch", NULL), 0,
					win.ws_col - 1));
		cursor->line_pos--;
	}
	else if (buffer == ARROW_RIGHT
		&& cursor->line_pos < ft_strlen(line))
	{
		if ((cursor->path_size + cursor->line_pos)
			% win.ws_col < win.ws_col - 1)
			ft_printf("%s", tgetstr("nd", NULL));
		else
			ft_printf("%s%s", tgetstr("do", NULL),
				tgoto(tgetstr("ch", NULL), 0, 0));
		cursor->line_pos++;
	}
}

void	key_home_end(char *line, int buffer, t_curs_pos *cursor)
{
	if (buffer == KEY_HOME)
	{
		while (cursor->line_pos)
			key_left_right(line, ARROW_LEFT, cursor);
	}
	else if (buffer == KEY_END)
		goto_endofline(cursor, line);
}

char	*arrow_keys(char *line, int buff, t_curs_pos *cursor, t_history **list)
{
	if (buff == ARROW_LEFT || buff == ARROW_RIGHT)
		key_left_right(line, buff, cursor);
	else if (buff == ARROW_UP || buff == ARROW_DOWN || buff == KEY_DLE)
		line = key_up_down(line, buff, cursor, list);
	else if (buff == KEY_HOME || buff == KEY_END)
		key_home_end(line, buff, cursor);
	return (line);
}
