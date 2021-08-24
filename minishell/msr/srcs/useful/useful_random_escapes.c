/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_random_escapes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:52:09 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/06/11 17:01:22 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_escapes(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_escaped(str, i) && str[i] != '\\' && str[i] != ';'
			&& str[i] != '|' && str[i] != '>' && str[i] != '<'
			&& str[i] != '$')
			return (-1);
		i++;
	}
	return (0);
}
