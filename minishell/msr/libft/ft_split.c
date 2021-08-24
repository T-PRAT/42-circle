/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 10:35:05 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/03/16 11:44:42 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**m_t(char ***str, int size)
{
	*str = malloc(size);
	return (*str);
}

static int	get_nb_str(const char *str, char c)
{
	int	i;
	int	nb;

	nb = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
			nb++;
		i++;
	}
	return (nb);
}

static char	*filloc_str(char *s, char c)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != c && s[i] != '\0')
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}

static char	**free_all(char **strs, int j)
{
	--j;
	while (j > 0)
		free(strs[j--]);
	free(strs);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s || !(char **)m_t(&strs, (get_nb_str(s, c) + 1) * sizeof(char *)))
		return (0);
	while (s[i])
	{
		if (s[i] != c)
		{
			strs[j] = filloc_str((char *)s + i, c);
			if (!strs[j])
				return (free_all(strs, j));
			j++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	strs[j] = NULL;
	return (strs);
}
