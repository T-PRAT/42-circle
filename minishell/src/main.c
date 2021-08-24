/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 15:46:40 by tprat             #+#    #+#             */
/*   Updated: 2021/08/24 20:25:41 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int ac, char **av, char **env)
{
	int		i;
	char	*line;

	i = -1;
	/*printf("ac:%d\n", ac);
	while (av[++i])
		printf("av[%d]:%s\n", i, av[i]);
	i = -1;
	while (env[++i])
		printf("env[%d]:%s\n", i, env[i]);*/
	printf("path:%s\n", getenv("PATH"));
	line = readline("➜ ");
	while (line)
	{
		parse_line(line);
		line = readline("➜ ");
	}
}
