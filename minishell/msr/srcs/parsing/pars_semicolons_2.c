/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_semicolons_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 19:57:42 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/06/23 20:14:30 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_empty_semicolons_str(char **strs, int nb)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		if (is_str_empty(strs[i]))
		{
			if (i < nb)
			{
				free_split(strs);
				return (-1);
			}
			free(strs[i]);
			strs[i] = NULL;
		}
		i++;
	}
	return (0);
}
