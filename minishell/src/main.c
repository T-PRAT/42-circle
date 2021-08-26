/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 15:46:40 by tprat             #+#    #+#             */
/*   Updated: 2021/08/26 16:39:43 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int ac, char **av, char **env)
{
	char	*line;
	t_ms	*ms;

	ms = malloc(sizeof(t_ms));
	//erreur
	ms->env = env;
	ms->path = ft_split(getenv("PATH"), ':');
	printf("path:%s\n", getenv("PATH"));
	line = readline("➜ ");
	while (line)
	{
		ft_pwd(ms->env);
		ms->tok = parse_line(line);
		line = readline("➜ ");
	}
}
