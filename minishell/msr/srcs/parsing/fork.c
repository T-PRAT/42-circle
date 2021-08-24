/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 17:00:33 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/06/24 16:15:35 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	save_fds(int *save)
{
	save[0] = dup(0);
	save[1] = dup(1);
}

void	reset_fds(int *save)
{
	dup2(save[0], 0);
	dup2(save[1], 1);
	close(save[0]);
	close(save[1]);
}

void	dup_in_close_new(int *new)
{
	dup2(new[0], 0);
	close(new[0]);
	close(new[1]);
}

int	fork_execute(char **command, t_env **env_list, int status, int *fd_tab)
{
	int		pid;
	int		new[2];
	char	*tmp;

	if ((status) && pipe(new) < 0)
		return (free_split_ret_error(command));
	pid = fork();
	if (pid == -1)
		return (free_split_ret_error(command));
	else if (!pid)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		if ((status) && dup2(new[1], 1) < 0)
			exit(2);
		exit(proceed_cmd(command, env_list, fd_tab));
	}
	wait(&pid);
	if (status)
		dup_in_close_new(new);
	tmp = ft_itoa(WEXITSTATUS(pid));
	if (!tmp)
		return (-1);
	env_change_value("?", tmp, *env_list);
	return (WEXITSTATUS(pid));
}
