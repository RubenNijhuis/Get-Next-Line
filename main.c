/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:01:44 by rnijhuis      #+#    #+#                 */
/*   Updated: 2021/10/28 12:01:45 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int	main(void)
{
	int				fd;
	unsigned int	i;
	char			*pojnter;
	char			**pojnterpojnter;

	pojnterpojnter = &pojnter;
	i = 0;
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error! Could not open file\n");
		exit(-1);
	}
	while (i < 3)
	{
		pojnter = get_next_line(fd);
		printf("%s", pojnter);
		i++;
		free(*pojnterpojnter);
	}
	while (1)
	{
	}
}
