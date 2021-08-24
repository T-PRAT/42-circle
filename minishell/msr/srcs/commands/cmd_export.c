/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 14:30:14 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/06/24 16:24:53 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_identifier(char *str)
{
	int	i;

	if (ft_isdigit(str[0]))
		return (1);
	i = 0;
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (1);
		i++;
	}
	return (0);
}

int	cmd_unset(char **cmd, t_env **list)
{
	int	i;
	int	ret;

	i = 1;
	ret = 0;
	while (cmd[i])
	{
		if (check_identifier(cmd[i]))
		{
			write(2, "Not a valid identifier\n", 23);
			ret = 1;
		}
		else
			*list = env_delete_link(*list, cmd[i]);
		i++;
	}
	return (ret);
}

void	print_export_output(t_env *list)
{
	while (list)
	{
		if (list->visible == true)
		{
			if (list->value)
				ft_printf("declare -x %s=\"%s\"\n", list->name, list->value);
			else
				ft_printf("declare -x %s\n", list->name);
		}
		list = list->next;
	}
}

int	add_empty_value(char *cmd, t_env **list)
{
	cmd = ft_strdup(cmd);
	if (!cmd)
		return (-1);
	*list = env_add_link(cmd, NULL, true, *list);
	if (!*list)
		return (-1);
	return (0);
}

int	cmd_export(char **cmd, t_env **list)
{
	int		i;
	int		ret;

	if (!cmd[1])
		print_export_output(*list);
	ret = 0;
	i = 1;
	while (cmd[i])
	{
		if (check_identifier(cmd[i]))
		{
			write(2, "Not a valid identifier\n", 23);
			ret = 1;
		}
		else if (ft_strchr(cmd[i] + 1, '='))
		{
			if (set_variable(cmd[i], list) == -1)
				return (-1);
			set_visible(cmd[i], *list);
		}
		else if (set_visible(cmd[i], *list) && add_empty_value(cmd[i], list))
			return (-1);
		i++;
	}
	return (ret);
}
