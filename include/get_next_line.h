/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:01:06 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/05/10 21:45:22 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

// Main
char		*get_next_line(int fd);

// Utils
uint32_t	check_line(char *line);
uint32_t	check_buffer(char *buffer);

// Buffer operation
void		reindex_buffer(char *buffer, uint32_t buf_line);
char		*create_newline(char *line, char *buffer, \
				uint32_t buf_size, uint32_t size_len);
char		*add_buffer(char *line, char *buffer, \
				uint32_t buf_line, uint32_t line_size);

#endif
