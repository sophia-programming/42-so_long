/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:21:13 by oaoba             #+#    #+#             */
/*   Updated: 2023/06/24 14:21:30 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <stdint.h>
# include <fcntl.h>
# include <stdbool.h>
# include "mlx_linux/mlx.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef enum e_type{
	TYPE_READ_SUCCESS = 1,
	TYPE_READ_EOF = 0,
	TYPE_READ_ERROR = -1,
}t_type;

typedef struct s_player
{
	int		pos_y;
	int		pos_x;
	int		num_of_steps;
	size_t	collectables;
}	t_player;

typedef struct s_map
{
	char	**map;
	size_t	width;
	size_t	height;
	size_t	num_of_collectables;
	size_t	num_of_players;
	size_t	num_of_exit;
}	t_map;

typedef struct s_images
{
	void	*empty;
	void	*wall;
	void	*collectible;
	void	*exit;
	void	*player;
	int		size;
}	t_images;

typedef struct s_info
{
	void		*mlx;
	void		*window;
	t_map		map_info;
	t_images	images;
	t_player	player;
}	t_info;

# define IMG_EMPTY 			"images/brack.xpm"
# define IMG_WALL 			"images/wall.xpm"
# define IMG_COLLECTIBLE	"images/item.xpm"
# define IMG_EXIT 			"images/goal.xpm"
# define IMG_PLAYER 		"images/cat.xpm"

# define OPEN_FAILURE -1

# define PIXEL_BITS	50
# define SCREEN_SIZE 20

# define ESC 65307

/*main.c*/
void	init_info(t_info *info);
char	**set_map(char *map_file, t_info *info);
void	setup_hooks(t_info *info);
void	check_player_position(char **map, t_info *conf);

/*error.c*/
void	check_argv(char *str);
void	put_error_message(t_info *info, char *message);
void	check_map_validity(char **map, t_info *info);

/*convert.c*/
char	**lst_to_map(t_list *buf, size_t height);
size_t	fd_to_lst(int fd, t_list **buf);

/*sl_get_next_line.c*/
size_t	x_strlen(const char *s, char c);
char	*get_buffer(int fd, char *buffer);
char	*trim_over_from_buffer(char *buffer);
char	*trim_result_from_buffer(char *buffer);
char	*get_next_line(int fd);

/*sl_get_next_line_utils.c*/
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);
char	*ft_gnl_strjoin(char *s1, char *s2);

/*check_map.c*/
void	check_map_rectangle(char **map, t_info *info);
void	check_map_wall(char **map, t_info *info);
void	check_map_loop(char **map, t_info *info, \
void func(char c, t_info *info));
void	check_map_empty(t_info *info);
void	check_map_validity(char **map, t_info *info);

/*check_map2.c*/
void	count_specific_char(char c, t_info *info);
void	check_invalid_char(char c, t_info *info);

/*mlx_part1.c*/
void	start_minilibx(t_info *info);
void	set_images(t_info *conf);
void	array_to_screen(char **map, t_info *info);

/*mlx_part2.c*/
int		key_hook(int keycode, t_info *info);
int		expose(t_info *conf);

/*mlx_free.c*/
char	**free_array(char **tab);
int		mlx_free(t_info *info);

/*action.c*/
void	player_move(int keycode, t_info *info);
void	step_to_next(char *current_position, char *next_position, t_info *info);
void	pedometer(t_info *info);
void	collect_item(char *a, char *b, t_info *info);
void	check_game_clear(char *a, char *b, t_info *info);
void	position_swap(char *a, char *b);

#endif
