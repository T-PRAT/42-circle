/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_env_pwd_cd_setvar.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:17:12 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/06/24 16:27:01 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	change_dir(char **cmd, t_env *list)
{
	char	*tmp;

	if (cmd[1])
	{
		chdir(cmd[1]);
		if (!ft_strcmp("//", cmd[1]))
		{
			tmp = ft_strdup("//");
			if (!tmp)
				return (-1);
			env_change_value("PWD", tmp, list);
		}
		else
			env_change_value("PWD", getcwd(NULL, 0), list);
	}
	else
	{
		chdir(getenv("HOME"));
		tmp = ft_strdup(getenv("HOME"));
		if (!tmp)
			return (-1);
		env_change_value("PWD", tmp, list);
	}
	return (0);
}

int	cmd_cd(char **cmd, t_env *list)
{
	if (change_dir(cmd, list) < 0)
		return (-1);
	if (errno == 2)
	{
		errno = 0;
		write(2, "Where ?\n", 8);
		return (1);
	}
	return (0);
}

int	cmd_pwd(char **cmd, t_env *list)
{
	if (cmd[1])
	{
		write(2, "Error : too many arguments\n", 27);
		return (1);
	}
	ft_printf("%s\n", env_get_value("PWD", list));
	return (0);
}

int	cmd_env(char **cmd, t_env *env_list)
{
	int	i;

	i = 0;
	if (cmd[1])
	{
		write(2, "Error : too many arguments\n", 27);
		return (1);
	}
	print_list_visible_only(env_list);
	return (0);
}

int	set_variable(char *cmd, t_env **list)
{
	int		i;
	char	*name;
	char	*value;

	i = 0;
	while (cmd[i] != '=' || is_escaped(cmd, i))
	{
		if (ft_isdigit(cmd[0]) || (!ft_isalnum(cmd[i]) && cmd[i] != '_'))
			return (0);
		i++;
	}
	cmd[i++] = '\0';
	value = ft_strdup(cmd + i);
	name = ft_strdup(cmd);
	if (!name || !value)
	{
		free(name);
		free(value);
		return (-1);
	}
	if (env_change_value(name, value, *list))
		free(name);
	else
		*list = env_add_link(name, value, false, *list);
	return (1);
}
