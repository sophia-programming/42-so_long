/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_part2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:21:18 by oaoba             #+#    #+#             */
/*   Updated: 2023/06/24 21:05:10 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_info *info)
{
	if (keycode == 'w' || keycode == 'a' || keycode == 's' || keycode == 'd')
		player_move(keycode, info);
	else if (keycode == ESC)
		mlx_free(info);
	check_player_position(info->map_info.map, info);
	if ((info->player.pos_y % SCREEN_SIZE) == 0 || \
	(info->player.pos_x % SCREEN_SIZE) == 0)
		mlx_clear_window(info->mlx, info->window);
	array_to_screen(info->map_info.map, info);
	return (0);
}

int	expose(t_info *conf)
{
	array_to_screen(conf->map_info.map, conf);
	return (0);
}

void	check_game_clear(char *a, char *b, t_info *info)
{
	if (info->player.collectables == info->map_info.num_of_collectables)
	{
		pedometer(info);
		*b = *a;
		*a = '0';
		ft_putendl_fd("Game Clear!!", STDERR_FILENO);
		mlx_free(info);
	}
}
