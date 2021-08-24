/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:24:11 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/06/14 17:58:43 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_double_pipes(char *str)
{
	int	i;

	i = 0;
	while (str[i + 1])
	{
		if (str[i] == '|' && str[i + 1] == '|'
			&& !is_escaped(str, i) && !is_inside_quotes(str, i))
			return (1);
		i++;
	}
	i++;
	while (i <= 0 && str[i] == ' ')
		i--;
	if (str[i] == '|' && !is_escaped(str, i))
		return (1);
	return (0);
}

int	get_nb_pipes(char *line)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (line[i])
	{
		if (line[i] == '|' && !is_inside_quotes(line, i)
			&& !is_escaped(line, i))
			nb++;
		i++;
	}
	return (nb);
}

char	**fill_split_pipes(char *line, char **strs)
{
	int		i;
	int		j;
	int		previous;

	previous = 0;
	i = 0;
	j = 0;
	while (previous < (int)ft_strlen(line))
	{
		while ((line[i] && (line[i] != '|'
					|| is_inside_quotes(line, i) || is_escaped(line, i))))
			i++;
		strs[j] = ft_strndup(line + previous, i - previous);
		if (!strs[j])
		{
			free_split(strs);
			return (NULL);
		}
		j++;
		while (line[i] == '|')
			i++;
		previous = i;
	}
	strs[j] = NULL;
	return (strs);
}

int	split_pipes(char *line, char ***commands)
{
	char	**strs;
	int		i;

	if (check_double_pipes(line))
		return (0);
	strs = malloc(sizeof(char *) * (get_nb_pipes(line) + 2));
	if (!strs)
		return (-1);
	strs = fill_split_pipes(line, strs);
	if (!strs)
		return (-1);
	i = 0;
	while (strs[i])
	{
		if (is_str_empty(strs[i]))
		{
			free_split(strs);
			return (0);
		}
		i++;
	}
	*commands = remove_escape_from_split(strs, '|', '|');
	if (!(*commands))
		return (-1);
	return (1);
}
