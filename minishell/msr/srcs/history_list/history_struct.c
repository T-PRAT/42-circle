/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 16:36:44 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/06/01 19:08:05 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	history_free_list(t_history *list)
{
	t_history	*next;

	while (list)
	{
		next = list->next;
		free(list->line);
		free(list);
		list = next;
	}
}

void	history_change_line(t_history *link, char *new_value)
{
	free(link->line);
	link->line = new_value;
}

t_history	*history_add_link(t_history *next, char *line)
{
	t_history	*new;

	new = malloc(sizeof(t_history));
	if (new)
	{
		new->next = next;
		if (next)
			new->next->previous = new;
		new->previous = NULL;
		new->line = line;
	}
	else
		history_free_list(next);
	return (new);
}

t_history	*history_del_first_link(t_history *link)
{
	t_history	*next;

	next = link->next;
	if (link->previous)
		link->previous->next = link->next;
	if (link->next)
		link->next->previous = link->previous;
	free(link);
	return (next);
}

void	history_print_list(t_history *list)
{
	while (list)
	{
		if (list->previous)
			ft_printf("\"%s\" ", list->previous->line);
		else
			ft_printf("%p ", list->previous);
		ft_printf("\"%s\"", list->line);
		if (list->next)
			ft_printf(" \"%s\"\n", list->next->line);
		else
			ft_printf(" %p\n", list->next);
		list = list->next;
	}
}
