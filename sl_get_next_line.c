/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:21:08 by oaoba             #+#    #+#             */
/*   Updated: 2023/06/24 14:21:30 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	x_strlen(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != c)
		len++;
	return (len);
}

char	*get_buffer(int fd, char *buffer)
{
	char	*storage;
	ssize_t	read_ret;

	storage = malloc(sizeof(char) * (BUFFER_SIZE + 1LL));
	if (storage == NULL)
		return (NULL);
	read_ret = TYPE_READ_SUCCESS;
	while (read_ret != TYPE_READ_EOF)
	{
		read_ret = read(fd, storage, BUFFER_SIZE);
		if (read_ret == TYPE_READ_ERROR)
		{
			free(storage);
			return (NULL);
		}
		storage[read_ret] = '\0';
		buffer = ft_gnl_strjoin(buffer, storage);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(storage);
	return (buffer);
}

char	*trim_over_from_buffer(char *buffer)
{
	size_t	i;
	size_t	over_str_len;
	char	*over_str;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	over_str_len = x_strlen(buffer, '\0') - i;
	over_str = malloc(sizeof(char) * (over_str_len + 1));
	if (over_str == NULL)
	{
		free(buffer);
		return (NULL);
	}
	ft_strlcpy(over_str, buffer + i + 1, over_str_len + 1);
	free(buffer);
	return (over_str);
}

char	*trim_result_from_buffer(char *buffer)
{
	size_t	i;
	char	*result;

	if (buffer == NULL)
		return (NULL);
	if (!ft_strchr(buffer, '\n'))
		result = ft_strdup(buffer);
	else
	{
		result = ft_calloc(x_strlen(buffer, '\n') + 2, sizeof(char));
		if (result == NULL)
			return (NULL);
		i = 0;
		while (buffer[i] != '\n')
		{
			result[i] = buffer[i];
			i++;
		}
		result[i] = '\n';
	}
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*over = NULL;
	char		*buffer;
	char		*result;

	if (fd < 0 || 256 < fd || BUFFER_SIZE <= 0 || INT_MAX < BUFFER_SIZE)
		return (NULL);
	buffer = get_buffer(fd, over);
	if (buffer == NULL)
		return (NULL);
	result = trim_result_from_buffer(buffer);
	over = trim_over_from_buffer(buffer);
	if (result[0] == '\0')
	{
		free(result);
		return (NULL);
	}
	return (result);
}

//int main(int argc, char **argv)
//{
//	if (argc != 2)
//	{
//		printf("%s", "Invalid argument function");
//		return 1;
//	}
//	int fd;
//	fd = open(argv[1], O_RDONLY);
//	char *line;
//	while (true)
//	{
//		line = get_next_line(fd);
//		if (line == NULL)
//			break;
//		printf("%s", line);
//		free(line);
//	}
//}