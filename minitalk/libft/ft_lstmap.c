/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:50:57 by tprat             #+#    #+#             */
/*   Updated: 2021/05/07 17:18:00 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *))
{
	t_list	*new;
	t_list	*first;

	first = ft_lstnew(f(lst->content));
	lst = lst->next;
	while (lst->next)
	{
		new = ft_lstnew(f(lst->content));
		ft_lstadd_back(&first, new);
		lst = lst->next;
	}
	new = ft_lstnew(f(lst->content));
	ft_lstadd_back(&first, new);
	return (lst);
}
