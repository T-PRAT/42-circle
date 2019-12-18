/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/18 16:35:07 by tprat        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 18:56:35 by tprat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
char	*ft_strjoin(char **line, char *buf);
char	*ft_strdup(const char *src);
char	*ft_strchr(const char *str, int c);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42

#endif
