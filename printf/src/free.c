/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:43:38 by tprat             #+#    #+#             */
/*   Updated: 2020/02/26 21:26:27 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_list(t_arg *current)
{
	t_arg	*tmp;

	while (current)
	{
		tmp = current->next;
		free(current->res);
		free(current->next);
		free(current);
		current = tmp;
	}
}
