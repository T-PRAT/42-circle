/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 18:43:22 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/06/14 14:43:49 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*add_char_to_line(char *line, char c, int pos)
{
	int		i;
	char	*new;

	new = malloc(sizeof(char) * (ft_strlen(line) + 2));
	if (new)
	{
		i = 0;
		while (i < pos)
		{
			new[i] = line[i];
			i++;
		}
		new[i] = c;
		while (line[i])
		{
			new[i + 1] = line[i];
			i++;
		}
		new[i + 1] = 0;
	}
	free(line);
	return (new);
}

char	*add_char(char *line, int buffer, t_curs_pos *cursor)
{
	line = add_char_to_line(line, buffer, cursor->line_pos);
	cursor->line_pos++;
	ft_printf("%s", tgetstr("im", NULL));
	write(1, &buffer, 1);
	ft_printf("%s", tgetstr("ei", NULL));
	return (line);
}

char	*delete_char_from_line(char *line, int pos)
{
	int		i;
	char	*new_line;

	i = 0;
	new_line = malloc(sizeof(char) * (ft_strlen(line)));
	if (new_line)
	{
		while (i < pos)
		{
			new_line[i] = line[i];
			i++;
		}
		while (line[i + 1])
		{
			new_line[i] = line[i + 1];
			i++;
		}
		new_line[i] = 0;
	}
	free(line);
	return (new_line);
}

char	*delete_left(char *line, t_curs_pos *cursor)
{
	if (cursor->line_pos > 0)
	{
		line = delete_char_from_line(line, cursor->line_pos - 1);
		if (!line)
			return (line);
		key_left_right(line, ARROW_LEFT, cursor);
		ft_printf("%s", tgetstr("sc", NULL));
		ft_printf("%s", tgetstr("ce", NULL));
		write(1, line + cursor->line_pos, ft_strlen(line + cursor->line_pos));
		ft_printf(" ");
		ft_printf("%s", tgetstr("rc", NULL));
	}
	return (line);
}

char	*delete_right(char *line, t_curs_pos *cursor)
{
	if (cursor->line_pos < ft_strlen(line))
	{
		line = delete_char_from_line(line, cursor->line_pos);
		if (!line)
			return (line);
		ft_printf("%s", tgetstr("sc", NULL));
		write(1, line + cursor->line_pos, ft_strlen(line + cursor->line_pos));
		ft_printf(" ");
		ft_printf("%s", tgetstr("rc", NULL));
	}
	return (line);
}
