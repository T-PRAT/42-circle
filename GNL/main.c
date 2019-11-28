#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int ac, char **av)
{
	int fd;
	char *line;
	int c;
	int i = 0;

	c = 1;
	if (ac != 2)
		printf("not enought arg");
	fd = open(av[1], O_RDONLY);
	printf("fd : %d\n", fd);
	if (fd == -1)
		printf("cant open file");
	while (c)
	{
		c = get_next_line(fd, &line);
		//printf("gnlreturn : %d\n", c);
		if (c == -1)
		{
			printf("error");
			return (0);
		}
		printf("ligne %d : \"%s\"\n", i, line);
		i++;
	}
	close(fd);
}
