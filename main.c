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
	*info = (t_info){0};
	info->images.size = PIXEL_BITS;
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
	int		col;
	int		row;

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
			row++;
		}
		col++;
	}
}

void	setup_hooks(t_info *info)
{
	int	key_pushed_mask;
	int	key_up_mask;
	int	window_update_event;

	key_pushed_mask = 1L << 0;
	key_up_mask = 1L << 17;
	window_update_event = 1L << 15;
	mlx_hook(info->window, 2, key_pushed_mask, key_hook, info);
	mlx_hook(info->window, 33, key_up_mask, mlx_free, info);
	mlx_hook(info->window, 12, window_update_event, expose, info);
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
