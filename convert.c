/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:21:46 by oaoba             #+#    #+#             */
/*   Updated: 2023/06/24 14:22:11 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	fd_to_lst(int fd, t_list **buf) //縦のサイズを知りたい
{
	char	*line;
	size_t	node_size;

	node_size = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (node_size == 0)
			*buf = ft_lstnew(line);
		else
			ft_lstadd_back(buf, ft_lstnew(line));
		node_size++;
	}
	return (node_size);
}

char	**lst_to_map(t_list *buf, size_t height)
{
	t_list	*tmp_node;
	size_t	i;
	char	**map;

	tmp_node = buf;
	map = (char **)malloc(sizeof(char *) * (height + 1));
	if (map == NULL)
		put_error_message(NULL, "map is not allocated.");
	i = 0;
	while (tmp_node)
	{
		map[i] = ft_strdup(tmp_node->content);
		if (map[i] == NULL)
			put_error_message(NULL, "map is not allocated");
		tmp_node = tmp_node->next;
		i++;
	}
	map[i] = NULL;
	ft_lstclear(&buf, free);
	return (map);
}
