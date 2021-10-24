#include "get_next_line_bonus.h"
#include <unistd.h>
#include <stdio.h>

// Return correct buffer based on fd
// Free list if malloc issue
t_list	*ft_lstadd_back(t_list *lst, t_list *new)
{
	if (!lst)
	{
		lst = new;
		return (new);
	}
	while (lst->next != NULL)
		lst = lst->next;
	lst->next = new;
	return (lst->next);
}

t_list	*ft_lstnew(int fd)
{
	struct s_list	*block;

	block = (t_list *) malloc(sizeof(*block));
	if (block == NULL)
		return (NULL);
	block->fd = fd;
	block->next = NULL;
	block->buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!block->buffer)
		return (NULL);
	return (block);
}

char *gnl_get_block(int fd, t_list *lst)
{
	if (lst == NULL)
	{
		lst = ft_lstnew(fd);
		printf("new block %d\n", lst->fd);
	}
	while (lst->next != NULL && lst->fd != fd)
		lst = lst->next;
	if (lst->fd == fd)
		return (lst->buffer);
	else
	{
		return (ft_lstadd_back(lst, ft_lstnew(fd))->buffer);
	}
}

char	*gnl_go_through_file(int fd, char *line, char *buffer)
{
	size_t	line_len;
	int		read_i;

	line[0] = 0;
	buffer[BUFFER_SIZE] = 0;
	if (buffer[0] != 0)
	{
		line = gnl_reindex_buf(buffer, line);
		if (line[gnl_strlen(line, 0) - 1] == '\n')
			return (line);
	}
	read_i = read(fd, buffer, BUFFER_SIZE);
	if (read_i < 0)
		return (NULL);
	while (read_i)
	{
		if (read_i < 0)
			return (NULL);
		line = gnl_reindex_buf(buffer, line);
		line_len = gnl_strlen(line, 0);
		if (line_len && line[line_len - 1] == '\n')
			return (line);
		read_i = read(fd, buffer, BUFFER_SIZE);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static struct s_list	*lst;
	char					*line;

	if (lst == NULL)
		lst = ft_lstnew(fd);

	if (fd < 0 || fd > 1024 || read(fd, 0, 0) == -1)
		return (NULL);
	line = malloc(sizeof(char) * 1);
	line = gnl_go_through_file(fd, line, gnl_get_block(fd, lst));
	if (!*line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
