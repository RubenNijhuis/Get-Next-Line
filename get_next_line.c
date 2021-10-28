#include "get_next_line.h"

static char	*go_through_file(char *line, int fd, char *buffer)
{
	int			size_line;
	int			buffer_size;

	size_line = 0;
	buffer_size = check_buffer(buffer);
	size_line += buffer_size;
	line = add_buffer(line, buffer, buffer_size, size_line);
	if (!check_line(line))
		return (line);
	while (read(fd, buffer, BUFFER_SIZE))
	{
		buffer_size = check_buffer(buffer);
		size_line += buffer_size;
		line = add_buffer(line, buffer, buffer_size, size_line);
		if (!check_line(line))
			break ;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || read(fd, buffer, 0) == -1)
		return (NULL);
	line = malloc(sizeof(char));
	if (line == NULL)
		return (NULL);
	line[0] = '\0';
	line = go_through_file(line, fd, buffer);
	if (line == NULL)
		return (NULL);
	if (!*line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
