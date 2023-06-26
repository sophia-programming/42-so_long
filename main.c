/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:21:40 by oaoba             #+#    #+#             */
/*   Updated: 2023/06/24 21:05:12 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_info(t_info *info)
{
	info->mlx = NULL;
	info->window = NULL;
	info->map_info.map = NULL;
	info->map_info.width = 0;
	info->map_info.height = 0;
	info->map_info.num_of_collectables = 0;
	info->map_info.num_of_players = 0;
	info->map_info.num_of_exit = 0;
	info->images.empty = NULL;
	info->images.wall = NULL;
	info->images.collectible = NULL;
	info->images.exit = NULL;
	info->images.player = NULL;
	info->images.size = PIXEL_BITS;
	info->player.pos_y = 0;
	info->player.pos_x = 0;
	info->player.num_of_steps = 0;
	info->player.collectables = 0;
}

char	**set_map(char *map_file, t_info *info)
{
	int		fd;
	t_list	*buf;

	buf = NULL;
	fd = open(map_file, O_RDONLY);
	if (fd == OPEN_FAILURE)
		put_error_message(info, "open failure.");
	info->map_info.height = fd_to_lst(fd, &buf);
	close(fd);
	if (info->map_info.height > INT_MAX)
		put_error_message(info, "height is too high.");
	return (lst_to_map(buf, info->map_info.height));
}

void	check_player_position(char **map, t_info *info)
{
	size_t		col;
	size_t		row;

	col = 0;
	while (map[col])
	{
		row = 0;
		while (map[col][row] != '\0')
		{
			if (map[col][row] == 'P')
			{
				info->player.pos_y = col;
				info->player.pos_x = row;
			}
			row += 1;
		}
		col += 1;
	}
}

void	setup_hooks(t_info *info)
{
	mlx_hook(info->window, 2, 1L << 0, key_hook, info);
	mlx_hook(info->window, 33, 1L << 17, mlx_free, info);
	mlx_hook(info->window, 12, 1L << 15, expose, info);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 2)
		put_error_message(NULL, "argc is not 2.");
	check_argv(argv[1]);
	init_info(&info);
	info.map_info.map = set_map(argv[1], &info);
	check_map_validity(info.map_info.map, &info);
	check_player_position(info.map_info.map, &info);
	start_minilibx(&info);
	setup_hooks(&info);
	mlx_loop(info.mlx);
	return (0);
}
