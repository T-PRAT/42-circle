/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:39:26 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/06/10 14:22:56 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_option_n(char *str)
{
	int	i;

	if (str[0] != '-')
		return (0);
	i = 1;
	while (str[i] == 'n')
		i++;
	if (str[i] != '\0' || i == 1)
		return (0);
	return (1);
}

int	cmd_echo(char **cmd)
{
	int		i;
	bool	n_option;

	i = 1;
	n_option = false;
	while (cmd[i] && is_option_n(cmd[i]))
	{
		n_option = true;
		i++;
	}
	while (cmd[i])
	{
		if (i > 1 && !is_option_n(cmd[i - 1]))
			write(1, " ", 1);
		ft_printf("%s", cmd[i++]);
	}
	if (!n_option)
		write(1, "\n", 1);
	return (0);
}
