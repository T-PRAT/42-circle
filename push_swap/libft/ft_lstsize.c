/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:03:59 by tprat             #+#    #+#             */
/*   Updated: 2021/05/07 17:18:58 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		c;
	t_list	*current;

	c = 0;
	current = lst;
	while (current)
	{
		current = current->next;
		c++;
	}
	return (c);
}
