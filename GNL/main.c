#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
	int fd;
	char **line;

	line = 0;
	if (!(fd = open("file", O_RDONLY)))
		printf("cant open file");
	if (get_next_line(fd, line) == -1)
		printf("error");
	printf("%s\n", *line);
}
