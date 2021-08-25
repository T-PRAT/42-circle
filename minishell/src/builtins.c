/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:53:38 by tprat             #+#    #+#             */
/*   Updated: 2021/08/25 15:34:23 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_echo(char *str, char opt)
{
	ft_putstr_fd(str, 1);
	if (opt != 'n')
		ft_putchar_fd('\n', 1);
}

void	ft_cd(char *path)
{
	chdir(path);
}

void	ft_pwd(char **env)
{
	printf("%s\n", getenv("PWD"));
}
