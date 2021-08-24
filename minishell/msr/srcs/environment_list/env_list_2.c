/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:46:26 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/06/24 15:10:54 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_print_list(t_env *list)
{
	while (list)
	{
		ft_printf("(%d)%s=%s\n", list->visible, list->name, list->value);
		list = list->next;
	}
}

void	print_list_visible_only(t_env *list)
{
	while (list)
	{
		if (list->visible == true && list->value)
			ft_printf("%s=%s\n", list->name, list->value);
		list = list->next;
	}
}

int	set_visible(char *name, t_env *list)
{
	while (list && ft_strcmp(list->name, name))
		list = list->next;
	if (list)
		list->visible = true;
	else
		return (1);
	return (0);
}

int	set_invisible(char *name, t_env *list)
{
	while (list && ft_strcmp(list->name, name))
		list = list->next;
	if (list)
		list->visible = false;
	else
		return (1);
	return (0);
}
