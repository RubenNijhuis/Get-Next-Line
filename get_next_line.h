/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:01:06 by rnijhuis      #+#    #+#                 */
/*   Updated: 2021/11/01 10:04:06 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

int		check_line(char *line);
void	reindex_buffer(char *buffer, int buf_line);
char	*create_newline(char *line, char *buffer, int buf_size, int size_len);
char	*add_buffer(char *line, char *buffer, int buf_line, int line_size);
int		check_buffer(char *buffer);
char	*get_next_line(int fd);

#endif