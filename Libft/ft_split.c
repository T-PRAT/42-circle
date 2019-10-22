/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 11:58:39 by tprat        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/14 11:56:54 by tprat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		count_word(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i] != 0)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

int		word_size(int index, char const *s, char c)
{
	int i;

	i = 0;
	while (s[index + i] != c && s[index + i])
		i++;
	return (i);
}

int		fill_word(char *str, int index, char const *s, char c)
{
	int i;

	i = 0;
	while (s[index] != c && s[index])
	{
		str[i] = s[index];
		index++;
		i++;
	}
	str[i] = 0;
	return (index);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;
	int		index;
	int		wrd_nbr;

	i = 0;
	index = 0;
	wrd_nbr = count_word(s, c);
	if (!(strs = malloc(sizeof(char *) * (wrd_nbr + 1))))
		return (0);
	while (i < wrd_nbr)
	{
		while (s[index] == c && s[index])
			index++;
		if (!(strs[i] = malloc(sizeof(char) * (word_size(index, s, c) + 1))))
			return (0);
		index = fill_word(strs[i], index, s, c);
		if (index == 0)
			return (0);
		i++;
	}
	strs[i] = 0;
	return (strs);
}
