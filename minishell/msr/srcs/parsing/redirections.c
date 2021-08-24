/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:12:28 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/06/15 13:03:34 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_fd_tab(int *fd)
{
	if (fd[0] < 0 || fd[1] < 0)
	{
		if (errno == 1 || errno == 2 || errno == 13)
		{
			write(2, strerror(errno), ft_strlen(strerror(errno)));
			write(2, "\n", 1);
			errno = 0;
			return (0);
		}
		else
			return (-1);
	}
	return (1);
}

int	**init_tab(char **command)
{
	int	nb;
	int	i;
	int	**tab;

	i = 0;
	nb = 0;
	while (command[nb])
		nb++;
	tab = malloc(sizeof(int *) * (nb + 1));
	if (!tab)
		return (NULL);
	while (i < nb)
	{
		tab[i] = malloc(sizeof(int) * 2);
		if (!tab[i])
		{
			free_split((char **)tab);
			return (NULL);
		}
		tab[i][0] = 0;
		tab[i][1] = 1;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

int	pars_out(char **command, int *fd_tab)
{
	int	i;
	int	ret;

	i = 0;
	while (command[0][i] && (is_inside_quotes(command[0], i)
		|| command[0][i] != '>' || is_escaped(command[0], i)))
		i++;
	if ((int)ft_strlen(command[0]) > i)
	{
		ret = open_out(command, i, fd_tab);
		if (ret < 1)
			return (ret);
		return (pars_out(command, fd_tab));
	}
	return (1);
}

int	pars_in(char **command, int *fd_tab)
{
	int	i;
	int	ret;

	i = 0;
	while (command[0][i] && (is_inside_quotes(command[0], i)
		|| command[0][i] != '<' || is_escaped(command[0], i)))
		i++;
	if ((int)ft_strlen(command[0]) > i)
	{
		ret = open_in(command, i, fd_tab);
		if (ret < 1)
			return (ret);
		return (pars_in(command, fd_tab));
	}
	return (1);
}

int	redirection(char **command, int ***fd_tab)
{
	int	i;
	int	ret_in;
	int	ret_out;

	i = 0;
	*fd_tab = init_tab(command);
	if (!*fd_tab)
		return (0);
	while (command[i])
	{
		ret_out = pars_out(command + i, (*fd_tab)[i]);
		if (ret_out == -1)
			return (free_split_ret_error((char **)(*fd_tab)));
		ret_in = pars_in(command + i, (*fd_tab)[i]);
		if (ret_in == -1)
			return (free_split_ret_error((char **)(*fd_tab)));
		if (ret_in == 0 || ret_out == 0)
			return (free_split_perror_ret_0((char **)*fd_tab));
		i++;
	}
	command = remove_escape_from_split(command, '<', '>');
	if (!command)
		return (-1);
	return (1);
}
