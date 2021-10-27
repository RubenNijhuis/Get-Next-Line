#include "get_next_line.h"

int	check_line(char *line)
{
	while (*line)
	{
		if (*line == '\n')
			return (0);
		line++;
	}
	return (1);
}

void	reindex_buffer(char *buffer, int buffer_size)
{
	int		i;

	i = 0;
	while (buffer_size < BUFFER_SIZE)
	{
		buffer[i] = buffer[buffer_size];
		buffer_size++;
		i++;
	}
	while (i < BUFFER_SIZE)
	{
		buffer[i] = '\0';
		i++;
	}
}

char	*create_newline(char *line, char *buffer, int buffer_size, int size_line)
{
	int	i;
	int	j;
	char *new_line;

	i = 0;
	j = 0;
	new_line = malloc((size_line + 1) * sizeof(char));
	if (new_line == NULL)
		return (NULL);
	while (line[i])
	{
		new_line[i] = line[i];
		i++;
	}
	while (j < buffer_size)
	{
		new_line[i] = buffer[j];
		i++;
		j++;
	}
	new_line[i] = '\0';
	return (new_line);
}

char	*add_buffer(char *line, char *buffer, int buffer_size, int size_line)
{
	char	*new_line;

	new_line = create_newline(line, buffer, buffer_size, size_line);
	if (new_line == NULL)
		return (NULL);
	reindex_buffer(buffer, buffer_size);
	free(line);
	return (new_line);
}

int	check_buffer(char *buffer)
{
	int	i;

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
