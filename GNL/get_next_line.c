/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/04 19:16:32 by tprat        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 19:39:32 by tprat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	int			rsize;
	int			v;
	static char	buf[BUFFER_SIZE];
	char		*tmp;

	if (fd < 0)
		return (-1);
	if (!(buf))
	{
		if (!(buf = calloc(BUFFER_SIZE, sizeof(char))))
			return (-1);
	}
	while (rsize)
	{
		if (buf[0])
		{
			*line = ft_strdup(buf);
			tmp = buf;
			buf = ft_strdup(ft_strchr(buf, '\n'));
			free(tmp);
		}
		if ((rsize = read(fd, buf, BUFFER_SIZE)) == -1)
			return (-1);
	}
	return (1);
}
