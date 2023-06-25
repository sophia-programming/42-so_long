/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:21:43 by oaoba             #+#    #+#             */
/*   Updated: 2023/06/24 14:22:11 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_argv(char *argv)
{
	char	*point;

	point = ft_strchr(argv, '.');
	if (point == NULL)
		put_error_message(NULL, ". is nothing");
	else
	{
		if (ft_strncmp(point, ".ber\0", 5) != 0)
			put_error_message(NULL, ".ber is nothing");
	}
}

void	put_error_message(t_info *info, char *message)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(message, 2);
	if (info != NULL)
		mlx_free(info);
	exit(EXIT_FAILURE);
}
