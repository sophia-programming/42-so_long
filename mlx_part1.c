/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_part1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:21:23 by oaoba             #+#    #+#             */
/*   Updated: 2023/06/24 21:05:11 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_images(t_info *info)
{
	info->images.empty = mlx_xpm_file_to_image(info->mlx, IMG_EMPTY, \
		&(info->images.size), &(info->images.size));
	if (info->images.empty == NULL)
		put_error_message(info, "IMG_EMPTY is not allocated.");
	info->images.wall = mlx_xpm_file_to_image(info->mlx, IMG_WALL, \
		&(info->images.size), &(info->images.size));
	if (info->images.wall == NULL)
		put_error_message(info, "IMG_WALL is not allocated.");
	info->images.collectible = mlx_xpm_file_to_image(info->mlx, \
		IMG_COLLECTIBLE, &(info->images.size), &(info->images.size));
	if (info->images.collectible == NULL)
		put_error_message(info, "IMG_COLLECTIBLE is not allocated.");
	info->images.exit = mlx_xpm_file_to_image(info->mlx, IMG_EXIT, \
		&(info->images.size), &(info->images.size));
	if (info->images.exit == NULL)
		put_error_message(info, "IMG_EXIT is not allocated.");
	info->images.player = mlx_xpm_file_to_image(info->mlx, IMG_PLAYER, \
		&(info->images.size), &(info->images.size));
	if (info->images.player == NULL)
		put_error_message(info, "IMG_PLAYER is not allocated.");
}

void	*get_img(char point_of_map, t_info *info)
{
	if (point_of_map == '0')
		return (info->images.empty);
	else if (point_of_map == '1')
		return (info->images.wall);
	else if (point_of_map == 'C')
		return (info->images.collectible);
	else if (point_of_map == 'E')
		return (info->images.exit);
	else if (point_of_map == 'P')
		return (info->images.player);
	else
	{
		put_error_message(info, "image is not exist.");
		return (NULL);
	}
}

void	array_to_screen(char **map, t_info *info)
{
	void	*img;
	size_t	small_x;
	size_t	small_y;
	size_t	large_x;
	size_t	large_y;

	large_y = (info->player.pos_y / SCREEN_SIZE) * SCREEN_SIZE;
	large_x = (info->player.pos_x / SCREEN_SIZE) * SCREEN_SIZE;
	small_y = 0;
	while (map[large_y + small_y])
	{
		small_x = 0;
		while (map[large_y + small_y][large_x + small_x] != '\0')
		{
			img = get_img(map[large_y + small_y][large_x + small_x], info);
			if (img == NULL)
				return ;
			mlx_put_image_to_window(info->mlx, info->window, img, \
				PIXEL_BITS * small_x, PIXEL_BITS * small_y);
			small_x++;
		}
		small_y++;
	}
}

void	start_minilibx(t_info *info)
{
	int	size_x;
	int	size_y;

	info->mlx = mlx_init();
	if (info->mlx == NULL)
		put_error_message(info, "mlx is not initialize.");
	set_images(info);
	size_x = ((int)(info->map_info.width)) * PIXEL_BITS;
	size_y = ((int)(info->map_info.height)) * PIXEL_BITS;
	if (info->map_info.width > SCREEN_SIZE)
		size_x = SCREEN_SIZE * (PIXEL_BITS + 1);
	if (info->map_info.height > SCREEN_SIZE)
		size_y = SCREEN_SIZE * (PIXEL_BITS + 1);
	info->window = mlx_new_window(info->mlx, size_x, size_y, "so_long");
	if (info->mlx == NULL)
		put_error_message(info, "window is not open.");
	array_to_screen(info->map_info.map, info);
}
