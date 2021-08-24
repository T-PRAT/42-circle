/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_split_returns.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:07:48 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/06/10 19:17:48 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	free_split_ret_error(char **split)
{
	int	i;

	i = 0;
	if (split)
	{
		while (split[i])
			free(split[i++]);
		free(split);
	}
	return (-1);
}

int	free_split_perror_ret_0(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	write(2, "Syntax error\n", 13);
	return (0);
}
