/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:43:38 by tprat             #+#    #+#             */
/*   Updated: 2020/02/25 19:07:26 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_list(t_arg *current)
{
	t_arg	*tmp;

	while (current)
	{
		if (!tmp)
			tmp = current->next;
		free(current->res);
		free(current->next);
		free(current);
		current = tmp;
	}
}
