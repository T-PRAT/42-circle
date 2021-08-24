/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proceed_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:50:41 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/06/24 16:16:13 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmd_searching(char **cmd, t_env **env_list)
{
	int		ret;
	char	*tmp;

	if (!ft_strcmp(cmd[0], "env"))
		ret = cmd_env(cmd, *env_list);
	else if (!ft_strcmp(cmd[0], "export"))
		ret = cmd_export(cmd, env_list);
	else if (!ft_strcmp(cmd[0], "unset"))
		ret = cmd_unset(cmd, env_list);
	else if (!ft_strcmp(cmd[0], "cd"))
		ret = cmd_cd(cmd, *env_list);
	else if (!ft_strcmp(cmd[0], "pwd"))
		ret = cmd_pwd(cmd, *env_list);
	else if (!ft_strcmp(cmd[0], "echo"))
		ret = cmd_echo(cmd);
	else
		ret = cmd_execve(cmd, *env_list);
	tmp = ft_itoa(ret);
	if (!tmp)
		return (-1);
	env_change_value("?", tmp, *env_list);
	return (ret);
}

int	proceed_cmd(char **cmd, t_env **env_list, int *fd_tab)
{
	int		ret;
	int		save[2];

	ret = 0;
	save_fds(save);
	if (fd_tab[0] != 0)
		dup2(fd_tab[0], 0);
	if (fd_tab[1] != 1)
		dup2(fd_tab[1], 1);
	if (cmd[0])
		ret = cmd_searching(cmd, env_list);
	reset_fds(save);
	return (ret);
}
