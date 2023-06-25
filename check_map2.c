/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:21:50 by oaoba             #+#    #+#             */
/*   Updated: 2023/06/24 21:05:15 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_specific_char(char c, t_info *info)
{
	if (c == 'C')
		info->map_info.num_of_collectables += 1;
	if (c == 'E')
		info->map_info.num_of_exit += 1;
	if (c == 'P')
		info->map_info.num_of_players += 1;
	if (info->map_info.num_of_collectables > INT_MAX || \
	info->map_info.num_of_exit > INT_MAX)
		put_error_message(info, "Too many C or E.");
}

void	check_invalid_char(char c, t_info *info)
{
	if (ft_strchr("01CEP", c) == NULL)
		put_error_message(info, "illegal pixel exists on map.");
}
