/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 19:15:30 by tprat             #+#    #+#             */
/*   Updated: 2021/08/26 16:55:31 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**tokenize(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		while (line[i] == ' ')
			i++;
	}
}

t_tok	*parse_line(char *line)
{
	t_tok	*tok;

	return (tok);
}
