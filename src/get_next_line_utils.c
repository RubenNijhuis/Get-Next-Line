/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:00:56 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/05/16 13:53:30 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

void	reindex_buffer(char *buffer, uint32_t buf_line)
{
	uint32_t	i;

	i = 0;
	while (buf_line < BUFFER_SIZE)
	{
		buffer[i] = buffer[buf_line];
		buf_line++;
		i++;
	}
	while (i < BUFFER_SIZE)
	{
		buffer[i] = '\0';
		i++;
	}
}

char	*create_newline(char *line, char *buffer, \
	uint32_t buf_size, uint32_t line_size)
{
	uint32_t	i;
	uint32_t	j;
	char		*new_line;

	i = 0;
	j = 0;
	new_line = malloc((line_size + 1) * sizeof(char));
	if (new_line == NULL)
		return (NULL);
	while (line[i])
	{
		new_line[i] = line[i];
		i++;
	}
	while (j < buf_size)
	{
		new_line[i] = buffer[j];
		i++;
		j++;
	}
	new_line[i] = '\0';
	return (new_line);
}
