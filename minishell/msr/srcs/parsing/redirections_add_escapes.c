/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_add_escapes.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:08:13 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/06/14 18:37:33 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	copy_str_to_new(char *str, char *new)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if ((str[i] == '=' || str[i] == '\\') && is_inside_quotes(str, i))
			new[j++] = '\\';
		new[j++] = str[i++];
	}
	new[j] = '\0';
}

char	*add_escapes_equal(char *str)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	while (str[i])
	{
		if ((str[i] == '=' || str[i] == '\\') && is_inside_quotes(str, i))
			j++;
		i++;
	}
	new = malloc(sizeof(char) * (ft_strlen(str) + j + 1));
	if (!new)
	{
		free(str);
		return (NULL);
	}
	copy_str_to_new(str, new);
	free(str);
	return (new);
}
