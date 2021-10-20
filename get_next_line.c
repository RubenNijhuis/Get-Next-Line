#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

int	check_newline(char *s, size_t buf_size)
{
	unsigned int i;
	while (i < buf_size)
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char *get_next_line(int fd)
{
	char line[BUFFER_SIZE];
	size_t bytes_read;


	bytes_read = read(fd, line, 20);
	return (line);
}