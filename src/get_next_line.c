/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 11:58:54 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/05/16 13:52:40 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#ifndef OPEN_MAX
# define OPEN_MAX (1024)
#endif

static uint32_t	check_buffer(char *buffer)
{
	uint32_t	i;

	i = 0;
	if (buffer == NULL)
		return (0);
	while (i < BUFFER_SIZE)
	{
		if (buffer[i] == '\n')
			return (i + 1);
		else if (buffer[i] == '\0')
			return (i);
		i++;
	}
	return (i);
}

static char	*add_buffer(char *line, char *buffer, \
	uint32_t buf_line, uint32_t line_size)
{
	char	*new_line;

	new_line = create_newline(line, buffer, buf_line, line_size);
	if (new_line == NULL)
		return (NULL);
	reindex_buffer(buffer, buf_line);
	free(line);
	return (new_line);
}

static uint32_t	check_line(char *line)
{
	while (*line)
	{
		if (*line == '\n')
			return (0);
		line++;
	}
	return (1);
}

static char	*go_through_file(char *line, int32_t fd, char *buffer)
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

char	*get_next_line(int32_t fd)
{
	static char	buffer[BUFFER_SIZE][OPEN_MAX];
	char		*line;

	if (fd < 0 || fd >= OPEN_MAX || read(fd, buffer, 0) == -1)
		return (NULL);
	line = malloc(sizeof(char));
	if (line == NULL)
		return (NULL);
	line[0] = '\0';
	line = go_through_file(line, fd, buffer[fd]);
	if (line == NULL)
		return (NULL);
	if (!*line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
