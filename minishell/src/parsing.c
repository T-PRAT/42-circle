/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 19:15:30 by tprat             #+#    #+#             */
/*   Updated: 2021/08/25 17:23:10 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	parse_line(char *line)
{
	char	**token;

	token = ft_split(line, ' ');
	for (int i=0; token[i]; i++)
	{
		printf("token:%s\n", token[i]);
	}

}
