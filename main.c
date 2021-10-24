#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int	main(void)
{
	int				fd1;
	int				fd2;
	unsigned int	i;

	i = 0;
	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("notes.txt", O_RDONLY);

	if (fd1 == -1 || fd2 == -1)
	{
		printf("Error! Could not open file\n");
		exit(-1);
	}
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd2));
}
