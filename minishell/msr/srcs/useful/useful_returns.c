/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_returns.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 14:40:53 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/06/23 20:20:58 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	error_ret_0(char *error)
{
	write(2, error, ft_strlen(error));
	write(2, "\n", 1);
	return (0);
}

int	error_ret(char *str, t_env *env, struct termios saved, t_history *histo)
{
	if (env)
		env_free_list(env);
	if (histo)
		history_free_list(histo);
	else
		free(str);
	reset_input_mode(saved);
	write(2, "Error : ", 8);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
	signal(SIGINT, SIG_DFL);
	return (EXIT_FAILURE);
}

int	success_ret(char *str, t_env *env, struct termios saved, t_history *histo)
{
	int	r;
	int	x;

	x = 5;
	r = 0;
	while (str[x] && ft_strlen(str) > 5)
	{
		if (ft_isdigit(str[x]) == 0)
		{
			ft_putstr_fd("Bad arg with exit\n", 2);
			r = 255;
		}
		x++;
	}
	if (r != 255)
		r = (unsigned char)ft_atoi(str + 4);
	write(1, "exit\n", 5);
	reset_input_mode(saved);
	free(str);
	if (env)
		env_free_list(env);
	if (histo)
		history_free_list(histo);
	signal(SIGINT, SIG_DFL);
	return (r);
}

int	free_ret_error(char *line, char *error, int	ret)
{
	if (error)
	{
		write(2, error, ft_strlen(error));
		write(2, "\n", 1);
	}
	free(line);
	return (ret);
}
