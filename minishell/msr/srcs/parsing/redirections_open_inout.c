/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_open_inout.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 15:04:16 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/06/15 12:57:35 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_i_nb_chevrons(char **command, int *i, char c)
{
	int		nb_chevrons;

	nb_chevrons = 1;
	command[0][(*i)++] = '\0';
	while (command[0][*i] == c)
	{
		*i = *i + 1;
		nb_chevrons++;
	}
	return (nb_chevrons);
}

void	open_fds_out(char *name, int nb_chevrons, int *fd_tab)
{
	if (fd_tab[1] != 1)
		close(fd_tab[1]);
	if (nb_chevrons == 1)
		fd_tab[1] = open(name, O_WRONLY | O_CREAT | O_TRUNC,
				S_IRWXU | S_IRGRP | S_IROTH);
	else
		fd_tab[1] = open(name, O_WRONLY | O_CREAT | O_APPEND,
				S_IRWXU | S_IRGRP | S_IROTH);
	free(name);
}

int	open_out(char **command, int i, int *fd_tab)
{
	int		nb_chevrons;
	char	*str;

	nb_chevrons = init_i_nb_chevrons(command, &i, '>');
	if (nb_chevrons > 2)
		return (0);
	i = goto_start_of_name(command[0], i);
	str = dup_name(command[0], &i);
	if (!str)
		return (-1);
	if (!ft_strlen(str))
	{
		free(str);
		return (0);
	}
	open_fds_out(str, nb_chevrons, fd_tab);
	nb_chevrons = check_fd_tab(fd_tab);
	if (nb_chevrons < 1)
		return (nb_chevrons);
	str = ft_strjoin(command[0], command[0] + i);
	if (!str)
		return (-1);
	free(command[0]);
	command[0] = str;
	return (1);
}

void	open_fds_in(char *name, int nb_chevrons, int *fd_tab)
{
	if (fd_tab[0] != 0)
		close(fd_tab[0]);
	if (nb_chevrons == 1)
		fd_tab[0] = open(name, O_RDONLY,
				S_IRWXU | S_IRGRP | S_IROTH);
	else
		fd_tab[0] = open(name, O_RDONLY,
				S_IRWXU | S_IRGRP | S_IROTH);
	free(name);
}

int	open_in(char **command, int i, int *fd_tab)
{
	int		nb_chevrons;
	char	*str;

	nb_chevrons = init_i_nb_chevrons(command, &i, '<');
	if (nb_chevrons > 1)
		return (0);
	i = goto_start_of_name(command[0], i);
	str = dup_name(command[0], &i);
	if (!str)
		return (-1);
	if (!ft_strlen(str))
	{
		free(str);
		return (0);
	}
	open_fds_in(str, nb_chevrons, fd_tab);
	nb_chevrons = check_fd_tab(fd_tab);
	if (nb_chevrons < 1)
		return (nb_chevrons);
	str = ft_strjoin(command[0], command[0] + i);
	if (!str)
		return (-1);
	free(command[0]);
	command[0] = str;
	return (1);
}
