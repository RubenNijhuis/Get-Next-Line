#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

// STORE; Line
// AMOUNT_READ; BUFFER_SIZE
// FILE; src

// Read BUFFER_SIZE of FILE
// Check in STORE if there is a new line
// strjoin STORE with PREV_STORE
// if no PRE_STORE make empty STORE
// remainder of STORE to STORE2

int	check_newline(char *s, size_t buf_size)
{
	unsigned int i;

    i = 0;
    while (i < buf_size)
    {
		if (s[i] == 12)
			return (i);
		i++;
	}
	return (-1);
}

char *get_next_line(int fd)
{
    int bufferSize = 128;
    char line[bufferSize];
    char *line_ptr;
    size_t bytes_read;

    // while (check_newline(line, bufferSize) != -1)
    // {
    //     printf("%zu", bytes_read);
    // }
    bytes_read = read(fd, line, bufferSize);
    if (check_newline(line, bufferSize) > 0)
        printf("YES");
    line[bufferSize - 1] = '\0';
    line_ptr = ft_strjoin(ft_strdup(""), line);
    return (line_ptr);
}