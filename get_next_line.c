#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int BUFFER_SIZE = 32;
// STORE; Line
// AMOUNT_READ; BUFFER_SIZE
// FILE; src

// Read BUFFER_SIZE of FILE
// Check in STORE if there is a new line
// strjoin STORE with PREV_STORE
// if no PRE_STORE make empty STORE
// remainder of STORE to STORE2

char *make_line(char *s, char buf[], unsigned int bufferRead)
{
	char *new_line;
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	new_line = malloc((bufferRead + 1) * sizeof(char));
	while (s[i] != '\0')
	{
		new_line[i] = s[i];
		i++;
	}
	while (i - bufferRead > bufferRead)
	{
		new_line[i] = buf[j];
		j++;
		i++;
	}
	return (new_line);
}

int	check_newline(char *s, size_t buf_size)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	return (i);
}

char 	*get_next_line(int fd)
{	
	char		buf[BUFFER_SIZE];
	char			*line;
	unsigned int	bufferRead;
	
	line = malloc(sizeof(char));
	line[0] = '\0';
	bufferRead = 0;
	unsigned int i = 0;
	unsigned int j = 0;
	while (read(fd, buf, BUFFER_SIZE) && i < 3)
	{
		// buf has new text
		// if has newline check pos (i.e 10)
			// add line + 10 char and return
		// else add buf to line and restart loop
		
		// bufferRead += check_newline(buf, BUFFER_SIZE);
		line = make_line(line, buf, BUFFER_SIZE);
		// printf("%i", bufferRead);
		// if (check_newline(line, BUFFER_SIZE))
		// 	return (line);
		// return (line);
	}
}
