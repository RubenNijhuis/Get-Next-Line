#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

int		check_line(char *line);
void	reindex_buffer(char *buffer, int buffer_size);
char	*create_newline(char *line, char *buffer, int buf_size, int size_len);
char	*add_buffer(char *line, char *buffer, int buffer_size, int size_line);
int		check_buffer(char *buffer);
char	*get_next_line(int fd);

#endif