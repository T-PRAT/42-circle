/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_semicolons.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:24:11 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/06/23 20:19:44 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_str_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	check_double_semicolon(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i + 1])
	{
		if (str[i] == ';' && str[i + 1] == ';'
			&& !is_inside_quotes(str, i) && !is_escaped(str, i))
			return (1);
		i++;
	}
	return (0);
}

int	get_nb_semicolons(char *line)
{
	int		i;
	int		nb_semicolons;

	i = 0;
	nb_semicolons = 0;
	while (line[i])
	{
		if (line[i] == ';' && !is_inside_quotes(line, i)
			&& !is_escaped(line, i))
			nb_semicolons++;
		i++;
	}
	return (nb_semicolons);
}

char	**fill_split_semicolons(char *line, char **strs)
{
	int		i;
	int		j;
	int		previous;

	previous = 0;
	i = 0;
	j = 0;
	while (previous < (int)ft_strlen(line))
	{
		while (line[i] && (line[i] != ';'
				|| is_inside_quotes(line, i) || is_escaped(line, i)))
			i++;
		strs[j] = ft_strndup(line + previous, i - previous);
		if (!strs[j])
		{
			free_split(strs);
			return (NULL);
		}
		j++;
		while (line[i] == ';')
			i++;
		previous = i;
	}
	strs[j] = NULL;
	return (strs);
}

char	**split_semicolons(char *line)
{
	int		nb_semicolons;
	char	**strs;

	if (check_double_semicolon(line))
		return (NULL);
	nb_semicolons = get_nb_semicolons(line);
	strs = malloc(sizeof(char *) * (nb_semicolons + 2));
	if (!strs)
		return (NULL);
	strs = fill_split_semicolons(line, strs);
	if (!strs)
		return (NULL);
	if (check_empty_semicolons_str(strs, nb_semicolons))
		return (NULL);
	return (remove_escape_from_split(strs, ';', ';'));
}
