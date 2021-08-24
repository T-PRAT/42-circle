/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:33:54 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/06/24 16:06:54 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_quotes(char *line)
{
	int		i;
	bool	single_open;
	bool	double_open;

	i = 0;
	single_open = false;
	double_open = false;
	while (line[i])
	{
		if (line[i] == '\'' && !double_open)
		{
			if (single_open)
				single_open = false;
			else if (!is_escaped(line, i))
				single_open = true;
		}
		else if (line[i] == '\"' && !single_open && !is_escaped(line, i))
			double_open = !double_open;
		i++;
	}
	if (single_open || double_open)
		return (-1);
	return (0);
}

int	reset_fds_ret_error(int *save, int i)
{
	if (i > 1)
		reset_fds(save);
	return (-1);
}

int	pars_spaces(char **command, t_env **env_list, int **fd_tab)
{
	int		i;
	char	**line;
	int		status;
	int		save[2];

	i = 0;
	if (command[1])
		save_fds(save);
	while (command[i])
	{
		status = (command[i + 1] != NULL);
		if (i > 0)
			status += 2;
		line = split_spaces(command[i], *env_list);
		if (!line)
			return (reset_fds_ret_error(save, i));
		status = var_then_execute(line, env_list, status, fd_tab[i]);
		if (status < 0)
			return (reset_fds_ret_error(save, i));
		i++;
	}
	if (i > 1)
		reset_fds(save);
	return (0);
}

int	pars_pipes(char **commands, t_env **env_list)
{
	int		ret;
	int		i;
	int		**fd_tab;
	char	**command;

	i = 0;
	while (commands[i])
	{
		ret = split_pipes(commands[i++], &command);
		if (ret == 0)
			return (error_ret_0("Syntax error"));
		if (ret == -1)
			return (-1);
		ret = redirection(command, &fd_tab);
		if (ret == 0)
			return (free_split(command));
		if (ret == -1)
			return (free_split_ret_error(command));
		ret = pars_spaces(command, env_list, fd_tab);
		free_split(command);
		free_close_fd_tab(fd_tab);
		if (ret < 0)
			return (ret);
	}
	return (0);
}

int	pars_line(char *line, t_env **env_list)
{
	int		ret;
	char	**commands;

	if (!line)
		return (-1);
	if (check_quotes(line) || check_escapes(line))
		return (free_ret_error(line, "Syntax error", 0));
	commands = split_semicolons(line);
	free(line);
	if (errno)
		return (-1);
	if (!commands)
		return (error_ret_0("Syntax error"));
	ret = pars_pipes(commands, env_list);
	free_split(commands);
	return (ret);
}
