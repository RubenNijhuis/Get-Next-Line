#include "get_next_line.h"

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

char	*gnl_go_through_file(int fd, char *line, char *buffer)
{
	size_t	line_len;
	int		read_i;

	line[0] = 0;
	buffer[BUFFER_SIZE] = 0;
	if (buffer[0] != 0)
	{
		line = gnl_reindex_buf(buffer, line);
		if (line[gnl_strlen(line, 0) - 1] == '\n')
			return (line);
	}
	read_i = read(fd, buffer, BUFFER_SIZE);
	if (read_i < 0)
		return (NULL);
	while (read_i)
	{
		if (read_i < 0)
			return (NULL);
		line = gnl_reindex_buf(buffer, line);
		line_len = gnl_strlen(line, 0);
		if (line_len && line[line_len - 1] == '\n')
			return (line);
		read_i = read(fd, buffer, BUFFER_SIZE);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	char			*line;

	if (fd < 0 || fd > 1024 || read(fd, 0, 0) == -1)
		return (NULL);
	line = malloc(sizeof(char) * 1);
	line = gnl_go_through_file(fd, line, buffer);
	if (!*line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
