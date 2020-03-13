/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:43:38 by tprat             #+#    #+#             */
/*   Updated: 2020/03/13 00:18:04 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	free_list(t_arg *current)
{
	t_arg	*tmp;

	tmp = 0;
	while (current)
	{
		tmp = current->next;
		if (current->res)
			free(current->res);
		free(current);
		current = tmp;
	}
	if (tmp)
		free(tmp);
	return (0);
}
