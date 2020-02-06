/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   list.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprat <tprat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/06 19:25:30 by tprat        #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 20:34:23 by tprat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		fill_struct(const char *al, t_arg *curr)
{
	int i;

	i = 0;
	while ((ft_strchr("-0.*", al[i])))
		i++;
	if (i)
	{
		if (!(curr->flag = ft_substr(al, 0, i)))
			return (0);
	}
	else
		curr->flag = 0;
	if (ft_strchr("cspdiuxX%", al[i]))
		curr->type = al[i];
	return (1);
}

t_arg	*new_elem(const char *al)
{
	t_arg *new;

	if (!(new = (t_arg *)malloc(sizeof(t_arg))))
		return (0);
	if (!(fill_struct(al, new)))
		return (0);
	if (!(new->next = malloc(sizeof(t_arg))))
		return(0);
	if (!(new->first = malloc(sizeof(t_arg))))
		return(0);
	return (new);
}

t_arg	*get_args(const char *al)
{
	int		i;
	t_arg	*curr;
	t_arg	*first;
	t_arg	*prev;

	first = 0;
	prev = 0;
	i = 0;
	while (al[i])
	{
		if (al[i] == '%')
		{
			i++;
			if (!(curr = new_elem(al + i)))
				return (0);
			if (first)
				curr->first = first;
			else
				first = curr;
			if (prev)
				prev->next = curr;
			else
				curr = prev;
		}
		else
			i++;
	}
	return (first);
}
