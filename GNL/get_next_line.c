/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/04 19:16:32 by tprat        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/04 20:17:24 by tprat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	int		rsize;
	char	buf[BUFFER_SIZE];

	if ((rsize = read(fd, buf, BUFFER_SIZE)) == -1)
		return (-1);
	if (!(line = malloc(sizeof(char *))))
		return (-1);
	if (!(*line = malloc(sizeof(char) * rsize)))
		return (-1);
	while (rsize)
	{
		rsize--;
		*line[rsize] = buf[rsize];
	}
	return (1);
}
