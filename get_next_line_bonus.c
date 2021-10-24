#include "get_next_line_bonus.h"

// Return correct buffer based on fd
// Free list if malloc issue

char *get_fds_buffer(char *fds[], int fd)
{
	if (!fds[fd - 1])
	{
		fds[fd - 1] = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!fds[fd - 1])
			return (NULL);
		fds[fd - 1][BUFFER_SIZE] = '\0';
	}
	return (fds[fd - 1]);
}

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
	static char	*fds[OPEN_MAX];
	char		*line;

	line = malloc(sizeof(char) * 1);
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0 || !line)
		return (NULL);
	line = gnl_go_through_file(fd, line, get_fds_buffer(fds, fd));
	if (!*line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
