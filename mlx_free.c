/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:21:34 by oaoba             #+#    #+#             */
/*   Updated: 2023/06/24 21:05:12 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**free_array(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	return (NULL);
}

int	mlx_free(t_info *info)
{
	if (info->map_info.map != NULL)
		info->map_info.map = free_array(info->map_info.map);
	if (info->images.empty != NULL)
		mlx_destroy_image(info->mlx, info->images.empty);
	if (info->images.wall != NULL)
		mlx_destroy_image(info->mlx, info->images.wall);
	if (info->images.collectible != NULL)
		mlx_destroy_image(info->mlx, info->images.collectible);
	if (info->images.exit != NULL)
		mlx_destroy_image(info->mlx, info->images.exit);
	if (info->images.player != NULL)
		mlx_destroy_image(info->mlx, info->images.player);
	if (info->window != NULL)
		mlx_destroy_window(info->mlx, info->window);
	if (info->mlx != NULL)
	{
		mlx_destroy_display(info->mlx);
		mlx_loop_end(info->mlx);
		free(info->mlx);
	}
	exit (EXIT_FAILURE);
	return (0);
}
