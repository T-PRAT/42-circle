/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:50:04 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/06/28 20:36:35 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_nice_path(void)
{
	int		ret;

	ret = 0;
	if (g_sigint != 1)
	{
		ft_printf(ANSI_COLOR_BLUE);
		ret = ft_printf("minishell ");
		ft_printf(ANSI_COLOR_GREEN);
		ret += ft_printf(">> ");
		ft_printf(ANSI_COLOR_RESET);
	}
	if (g_sigint)
		g_sigint--;
	return (ret);
}

void	sigint_case(int truc)
{
	(void) truc;
	g_sigint = 2;
	write(0, "\n", 1);
	print_nice_path();
}

int	init_things(t_history **h, struct termios *sav, t_env **env_l, char **env)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sigint_case);
	*h = NULL;
	set_input_mode(sav);
	*env_l = create_env_list(env);
	if (!(*env_l) || init_termcaps())
		return (-1);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	char			*line;
	int				ret;
	t_env			*env_list;
	t_history		*histo_list;
	struct termios	saved;

	(void) argv;
	(void) argc;
	if (init_things(&histo_list, &saved, &env_list, env) < 0)
		exit(EXIT_FAILURE);
	while (666)
	{
		ret = print_nice_path();
		if (ret < 0)
			return (error_ret(NULL, env_list, saved, histo_list));
		line = get_line(ret, &histo_list);
		if (!line)
			return (error_ret(NULL, env_list, saved, histo_list));
		if ((!ft_strncmp(line, "exit", 4) && ft_strlen(line) == 4)
			|| !ft_strncmp(line, "exit ", 5))
			return (success_ret(line, env_list, saved, histo_list));
		if (pars_line(ft_strdup(line), &env_list) == -1)
			return (error_ret(line, env_list, saved, histo_list));
	}
	return (0);
}
