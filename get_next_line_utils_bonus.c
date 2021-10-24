#include "get_next_line.h"

size_t	gnl_strlen(char *str, int flag)
{
	size_t	len;

	len = 0;
	while (str[len] != 0 && len < BUFFER_SIZE && str[len] \
	!= '\n' && flag == 1)
		len++;
	while (str[len] != 0 && flag == 0)
		len++;
	return (len);
}

void	gnl_bzero(char	*str, size_t i)
{
	while (i < BUFFER_SIZE)
	{
		str[i] = 0;
		i++;
	}
}

void	*gnl_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	if (dst > src)
	{
		while (len > 0)
		{
			((char *)dst)[len - 1] = ((char *)src)[len - 1];
			len--;
		}
		return (dst);
	}
	while (len > i)
	{
		((char *)dst)[i] = ((char *) src)[i];
		i++;
	}
	return (dst);
}

char	*gnl_reindex_buf(char *buffer, char *line)
{
	size_t	i;
	char	*tmp;
	size_t	j;
	size_t	str_lenbuf;

	str_lenbuf = gnl_strlen(buffer, 1);
	tmp = (char *)malloc((gnl_strlen(line, 0) + \
	str_lenbuf + 1) * sizeof(char));
	j = 0;
	while (line[j] != '\0')
	{
		tmp[j] = line[j];
		j++;
	}
	i = 0;
	while (i < str_lenbuf + 1 && i < BUFFER_SIZE)
	{
		tmp[j + i] = buffer[i];
		i++;
	}
	gnl_memmove(buffer, buffer + i, BUFFER_SIZE - i);
	tmp[j + i] = 0;
	gnl_bzero(buffer, BUFFER_SIZE - i);
	free(line);
	return (tmp);
}
