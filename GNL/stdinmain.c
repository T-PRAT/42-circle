#include <stdio.h>
#include "get_next_line.h"

int main()
{
	int fd = 0;
	char *line;

	get_next_line(fd, &line);
	printf("|%s|", line);
	return (0);
}
