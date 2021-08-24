/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:15:35 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/06/28 19:38:32 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*path_join(char *path, char *cmd)
{
	char	*mid;
	char	*end;

	mid = ft_strjoin(path, "/");
	if (!mid)
		return (NULL);
	end = ft_strjoin(mid, cmd);
	free(mid);
	return (end);
}

char	*get_right_execve_path(char *cmd, char **paths)
{
	struct stat	truc;
	char		*right_path;
	int			i;

	i = 0;
	if (!stat(cmd, &truc))
		return (ft_strdup(cmd));
	while (paths[i])
	{
		right_path = path_join(paths[i], cmd);
		if (!right_path)
			return (NULL);
		if (!stat(right_path, &truc))
			return (right_path);
		free(right_path);
		i++;
	}
	return (ft_strdup(""));
}

int	execute_cmd(char **cmd, char *path, t_env *env_list)
{
	int		ret;
	char	**env_tab;

	ret = 0;
	env_tab = create_env_tab(env_list);
	if (!env_tab)
		return (-1);
	ret = execve(path, cmd, env_tab);
	if (!ret)
		errno = 0;
	free_split(env_tab);
	return (ret);
}

int	cmd_execve(char **cmd, t_env *env_list)
{
	char	**paths;
	char	*right_path;
	int		ret;

	paths = ft_split(env_get_value("PATH", env_list), ':');
	ret = -1;
	if (!paths)
		return (-1);
	right_path = get_right_execve_path(cmd[0], paths);
	free_split(paths);
	if (!right_path)
		return (-1);
	errno = 0;
	if (!right_path[0])
	{
		ft_printf("Wut ?\n");
		ret = 127;
	}
	else
		ret = execute_cmd(cmd, right_path, env_list);
	free(right_path);
	return (ret);
}
