/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:44:37 by tprat             #+#    #+#             */
/*   Updated: 2021/08/26 16:49:30 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_tok	*create_lst(char *cont)
{
	t_tok	*new;

	new = malloc(sizeof(t_tok));
	if (!(new))
		return (NULL);
	new->prev = NULL;
	new->next = NULL;
	return (new);
}
