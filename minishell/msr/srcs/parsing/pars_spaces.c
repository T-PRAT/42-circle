/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_spaces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 17:41:34 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/06/14 18:34:47 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	go_end_quotes(char *str, int i)
{
	char	c;

	c = str[i];
	while (str[i] != c)
		i++;
	return (i);
}

int	get_nb_spaces(char *line)
{
	int		i;
	int		nb_args;

	i = 0;
	nb_args = 0;
	while (line[i] == ' ')
		i++;
	while (line[i])
	{
		if (line[i] == ' ' && (i == 0 || line[i - 1] != ' '))
			nb_args++;
		else if (line[i] == '\'' || line[i] == '\"')
			i = go_end_quotes(line, i);
		i++;
	}
	if (line[i - 1] != ' ')
		nb_args++;
	return (nb_args);
}

char	*dup_next_word(char *l, int *i)
{
	int		j;
	int		i_save;
	char	*new;

	j = 0;
	i_save = *i;
	while (l[*i] && (l[*i] != ' ' || is_inside_quotes(l, *i)))
	{
		if ((l[*i] != '\"' && l[*i] != '\'') || is_inside_quotes(l, *i))
			j++;
		(*i)++;
	}
	new = malloc(sizeof(char) * (j + 1));
	if (!new)
		return (NULL);
	j = 0;
	while (l[i_save] && (l[i_save] != ' ' || is_inside_quotes(l, i_save)))
	{
		if ((l[i_save] != '\"' && l[i_save] != '\'')
			|| is_inside_quotes(l, i_save))
			new[j++] = l[i_save];
		i_save++;
	}
	new[j] = '\0';
	return (new);
}

int	copy_every_word(char *line, int nb_words, char **strs)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] && j < nb_words)
	{
		while (line[i] == ' ')
			i++;
		strs[j] = dup_next_word(line, &i);
		if (!strs[j++])
			return (free_split_ret_error(strs));
		if (line[i])
			i++;
	}
	strs[j] = NULL;
	return (0);
}

char	**split_spaces(char *line, t_env *env_list)
{
	int		nb_words;
	char	**strs;

	line = replace_vars(line, env_list);
	if (!line)
		return (NULL);
	line = add_escapes_equal(line);
	if (!line)
		return (NULL);
	nb_words = get_nb_spaces(line);
	strs = malloc(sizeof(char *) * (nb_words + 1));
	if (!strs || copy_every_word(line, nb_words, strs) < 0)
		return (NULL);
	free(line);
	return (strs);
}
