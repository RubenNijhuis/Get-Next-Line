#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

char	*get_next_line(int fd);
char	*gnl_reindex_buf(char *buffer, char *line);
void	*gnl_memmove(void *dst, const void *src, size_t len);
size_t	gnl_strlen(char *str, int flag);
void	gnl_bzero(char	*str, size_t i);

#endif
