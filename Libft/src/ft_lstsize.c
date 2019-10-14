/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstsize.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/14 17:03:59 by tprat        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/14 18:06:29 by tprat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int		c;
	t_list	*current;

	c = 0;
	current = lst;
	while (current->next != 0)
	{
		current = current->next;
		c++;
	}
	return (c);
}
