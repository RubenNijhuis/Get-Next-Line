/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:01:06 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/05/16 13:50:57 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

// Main
char	*get_next_line(int fd);

// Buffer operation
char	*create_newline(char *line, char *buffer, \
			uint32_t buf_size, uint32_t size_len);
void	reindex_buffer(char *buffer, uint32_t buf_line);

#endif
