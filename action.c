/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:21:55 by oaoba             #+#    #+#             */
/*   Updated: 2023/06/24 21:02:25 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_move(int keycode, t_info *info)
{
	int	x;
	int	y;

	x = info->player.pos_x;
	y = info->player.pos_y;
	if (keycode == 'w')
		step_to_next(&info->map_info.map[y][x], \
		&info->map_info.map[y - 1][x], info);
	if (keycode == 'a')
		step_to_next(&info->map_info.map[y][x], \
		&info->map_info.map[y][x - 1], info);
	if (keycode == 's')
		step_to_next(&info->map_info.map[y][x], \
		&info->map_info.map[y + 1][x], info);
	if (keycode == 'd')
		step_to_next(&info->map_info.map[y][x], \
		&info->map_info.map[y][x + 1], info);
}

void	pedometer(t_info *info)
{
	info->player.num_of_steps += 1;
	if (info->player.num_of_steps > INT_MAX)
		put_error_message(info, "step is too many");
	ft_printf("Number of steps: %d\n", info->player.num_of_steps);
}

void	collect_item(char *player, char *collectable, t_info *info)
{
	*collectable = *player;
	*player = '0';
	info->player.collectables += 1;
}

void	position_swap(char *player, char *empty)
{
	char	tmp;

	tmp = *player;
	*player = *empty;
	*empty = tmp;
}

void	step_to_next(char *current_position, char *next_position, t_info *info)
{
	if (*next_position == 'C' || *next_position == '0')
		pedometer(info);
	if (*next_position == 'C')
		collect_item(current_position, next_position, info);
	else if (*next_position == 'E')
		check_game_clear(current_position, next_position, info);
	else if (*next_position == '0')
		position_swap(current_position, next_position);
}
