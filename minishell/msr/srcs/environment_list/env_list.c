/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 18:38:45 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/06/01 19:07:09 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_free_list(t_env *list)
{
	t_env	*next;

	while (list)
	{
		next = list->next;
		free(list->name);
		free(list->value);
		free(list);
		list = next;
	}
}

t_env	*env_delete_link(t_env *list, char *name)
{
	t_env	*start;
	t_env	*next;
	t_env	*previous;

	previous = NULL;
	start = list;
	while (list && list->name && ft_strcmp(list->name, name))
	{
		previous = list;
		list = list->next;
	}
	if (!list)
		return (start);
	next = list->next;
	free(list->name);
	free(list->value);
	free(list);
	if (previous)
	{
		previous->next = next;
		return (start);
	}
	return (next);
}

t_env	*env_add_link(char *name, char *value, bool visible, t_env *next)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (new)
	{
		new->name = name;
		new->value = value;
		new->visible = visible;
		new->next = next;
	}
	else
		env_free_list(next);
	return (new);
}

char	*env_get_value(char *name, t_env *list)
{
	while (list && ft_strcmp(list->name, name))
		list = list->next;
	if (list)
		return (list->value);
	return (NULL);
}

int	env_change_value(char *name, char *value, t_env *list)
{
	while (list && ft_strcmp(list->name, name))
		list = list->next;
	if (list)
	{
		free(list->value);
		list->value = value;
		return (1);
	}
	return (0);
}
