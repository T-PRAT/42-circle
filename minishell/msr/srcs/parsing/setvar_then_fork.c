/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setvar_then_fork.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:06:09 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/06/24 16:16:38 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
int	set_all_variables(char **line, t_env **env_list)
{
	int	i;
	int	ret;

	i = 0;
	ret = 1;
	while (line[i] && line[i][0] != '='
		&& unescaped_strchr(line[i], '=') && ret != 0)
	{
		ret = set_variable(line[i], env_list);
		if (ret == -1)
			return (free_split_ret_error(line));
		if (ret == 0)
			i--;
		i++;
	}
	return (i);
}

int	var_then_execute(char **line, t_env **env_list, int status, int *fd_tab)
{
	int	i;
	int	ret;

	i = set_all_variables(line, env_list);
	if (i < 0)
		return (-1);
	ret = 0;
	line = remove_escape_from_split(line, '=', '\\');
	if (!line)
		return (-1);
	if (line[i] && !status && is_a_builtin(line[i]))
		ret = proceed_cmd(line + i, env_list, fd_tab);
	else if (line[i])
	{
		if (status == 2)
			status -= 2;
		ret = fork_execute(line + i, env_list, status, fd_tab);
	}
	free_split(line);
	return (ret);
}
