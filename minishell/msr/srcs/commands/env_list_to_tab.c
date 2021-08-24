/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:55:10 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/06/24 15:55:17 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_list_size(t_env *list)
{
	int		i;

	i = 0;
	while (list)
	{
		if (list->value)
			i++;
		list = list->next;
	}
	return (i);
}

char	*list_to_var(t_env *list)
{
	char	*str;
	int		i;

	i = ft_strlen(list->name);
	str = malloc(sizeof(char) * (i + ft_strlen(list->value) + 2));
	if (!str)
		return (NULL);
	ft_strlcpy(str, list->name, ++i);
	str[i - 1] = '=';
	ft_strlcpy(str + i, list->value, ft_strlen(list->value) + 1);
	return (str);
}

char	**create_env_tab(t_env *list)
{
	char	**tab;
	int		i;

	tab = malloc(sizeof(char *) * (get_list_size(list) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (list)
	{
		if (list->value)
		{
			tab[i] = list_to_var(list);
			if (!tab[i])
			{
				free_split(tab);
				return (NULL);
			}
			i++;
		}
		list = list->next;
	}
	tab[i] = NULL;
	return (tab);
}
