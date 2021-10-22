#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int	main(void)
{
	int				fd;
	unsigned int	i;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error! Could not open file\n");
		exit(-1);
	}
	while (i < 8)
		printf("%s", get_next_line(fd));
}
