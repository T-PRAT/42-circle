/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:26:59 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/06/04 15:29:59 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*add_question_mark(t_env *tab)
{
	char	*name;
	char	*value;

	name = ft_strdup("?");
	value = ft_strdup("0");
	if (!name || !value)
	{
		free(name);
		free(value);
		env_free_list(tab);
		return (NULL);
	}
	tab = env_add_link(name, value, false, tab);
	return (tab);
}

t_env	*create_env_list(char **env_tab)
{
	int		i;
	t_env	*env_list;
	char	*equal;

	i = 0;
	env_list = NULL;
	while (env_tab[i])
	{
		equal = ft_strchr(env_tab[i], '=');
		env_list = env_add_link(ft_strndup(env_tab[i], equal - env_tab[i]),
				ft_strdup(equal + 1), true, env_list);
		if (!env_list->name || !env_list->value)
		{
			env_list = env_delete_link(env_list, env_list->name);
			env_free_list(env_list);
			return (NULL);
		}
		i++;
	}
	return (add_question_mark(env_list));
}

void	set_input_mode(struct termios *saved_attributes)
{
	struct termios	new;

	tcgetattr(0, saved_attributes);
	tcgetattr(0, &new);
	new.c_lflag &= ~(ICANON | ECHO);
	new.c_cc[VMIN] = 1;
	new.c_cc[VTIME] = 0;
	tcsetattr (0, TCSAFLUSH, &new);
}

int	init_termcaps(void)
{
	char	*term;
	int		ret;

	term = getenv("TERM");
	if (!term)
	{
		ft_printf(ANSI_COLOR_RED "Variable TERM non initialisée\n"
			ANSI_COLOR_RESET);
		return (-1);
	}
	ret = tgetent(NULL, term);
	if (ret == 1)
		return (0);
	if (ret == -1)
		ft_printf(ANSI_COLOR_RED "BDD inaccessible\n"
			ANSI_COLOR_RESET);
	else if (ret == 0)
		ft_printf(ANSI_COLOR_RED "Terminal inconnu\n"
			ANSI_COLOR_RESET);
	return (-1);
}
