/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_null.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 17:56:06 by tprat             #+#    #+#             */
/*   Updated: 2020/03/04 17:59:33 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_null(const char *src)
{
	char	*dest;
	int		i;

	i = 0;
	if (!(src))
	{
		if (!(dest = ft_strdup("(null)")))
			return (0);
	}
	else
	{
		if (!(dest = ft_strdup(src)))
			return (0);
	}
	return (dest);

}
