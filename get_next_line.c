/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 11:58:54 by rnijhuis      #+#    #+#                 */
/*   Updated: 2021/11/01 10:07:53 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*go_through_file(char *line, int fd, char *buffer)
{
	int	line_size;
	int	buf_line;

	buf_line = check_buffer(buffer);
	line_size = buf_line;
	line = add_buffer(line, buffer, buf_line, line_size);
	if (!check_line(line))
		return (line);
	while (read(fd, buffer, BUFFER_SIZE))
	{
		buf_line = check_buffer(buffer);
		line_size += buf_line;
		line = add_buffer(line, buffer, buf_line, line_size);
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
