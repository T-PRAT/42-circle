/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_utils.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprat <tprat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/17 18:32:20 by tprat        #+#   ##    ##    #+#       */
/*   Updated: 2020/02/02 22:52:50 by tprat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_lstaddarg_back(t_arg **alst, t_arg *new)
{
	t_arg	*current;

	current = *alst;
	while (current->next)
		current = current->next;
	current->next = new;
}
