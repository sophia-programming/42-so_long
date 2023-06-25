/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:21:52 by oaoba             #+#    #+#             */
/*   Updated: 2023/06/24 21:05:15 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_rectangle(char **map, t_info *info)
{
	size_t	col;

	col = 0;
	while (map[col])
	{
		if (col == 0)
			(*info).map_info.width = ft_strlen(map[col]);
		if (info->map_info.width != ft_strlen(map[col]))
			put_error_message(info, "map is not rectangle.");
		col += 1;
	}
}

void	check_map_wall(char **map, t_info *info)
{
	size_t	col;
	size_t	row;

	col = 0;
	while (map[col])
	{
		row = 0;
		if (col == 0 || col == info->map_info.height - 1)
		{
			while (map[col][row] != '\0')
			{
				if (map[col][row] != '1')
					put_error_message(info, "map is not rectangle.");
				row += 1;
			}
		}
		else if (map[col][0] != '1' || \
		map[col][info->map_info.width - 1] != '1')
			put_error_message(info, "map is not rectangle");
		col += 1;
	}
}

void	check_map_loop(char **map, t_info *info, \
void func(char c, t_info *info))
{
	size_t	col;
	size_t	row;

	col = 0;

	while (map[col])
	{
		row = 0;
		while (map[col][row] != '\0')
		{
			func(map[col][row], info);
			row += 1;
		}
		col += 1;
	}
}

void	check_map_empty(t_info *info)
{
	if (info->map_info.num_of_exit != 1)
		put_error_message(info, "the number of exit should be one.");
	if (info->map_info.num_of_players != 1)
		put_error_message(info, "the number of player should be one");
	if (info->map_info.num_of_collectables == 0)
		put_error_message(info, "collectable doesn't exist");
}

void	check_map_validity(char **map, t_info *info)
{
	check_map_rectangle(map, info);
	check_map_wall(map, info);
	check_map_loop(map, info, check_invalid_char);
	check_map_loop(map, info, count_specific_char);
	check_map_empty(info);
}
