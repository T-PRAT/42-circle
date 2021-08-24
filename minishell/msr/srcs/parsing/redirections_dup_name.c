/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_dup_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 15:06:49 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/06/11 17:01:35 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_close_fd_tab(int **fd_tab)
{
	int	i;

	i = 0;
	while (fd_tab[i])
	{
		if (fd_tab[i][0] != 0)
			close(fd_tab[i][0]);
		if (fd_tab[i][1] != 1)
			close(fd_tab[i][1]);
		free(fd_tab[i]);
		i++;
	}
	free(fd_tab);
}

int	goto_start_of_name(char *str, int i)
{
	while (str[i] && str[i] == '>')
		i++;
	while (str[i] && str[i] == ' ')
		i++;
	return (i);
}

int	get_name_size(char *str)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i] && ((str[i] != ' ' && str[i] != '>' && str[i] != '<')
			|| is_inside_quotes(str, i)))
	{
		if ((str[i] != '\"' && str[i] != '\'' && str[i] != '\\')
			|| is_inside_quotes(str, i) || is_escaped(str, i))
			size++;
		i++;
	}
	return (i);
}

char	*dup_name(char *str, int *i)
{
	char	*new;
	int		j;

	new = malloc(sizeof(char) * (get_name_size(str + *i) + 1));
	if (!new)
		return (NULL);
	j = 0;
	while (str[*i] && ((str[*i] != ' ' && str[*i] != '>' && str[*i] != '<')
			|| is_inside_quotes(str, *i)))
	{
		if ((str[*i] != '\"' && str[*i] != '\'' && str[*i] != '\\')
			|| is_inside_quotes(str, *i) || is_escaped(str, *i))
			new[j++] = str[*i];
		(*i)++;
	}
	new[j] = '\0';
	return (new);
}
