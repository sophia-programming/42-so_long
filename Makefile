# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/24 14:21:37 by oaoba             #+#    #+#              #
#    Updated: 2023/06/24 14:22:11 by oaoba            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= 	gcc
CFLAGS			= 	-Wall -Wextra -Werror
NAME			= 	so_long
INCLUDES		= 	includes

LIBFT_PATH		= 	./libft/
FT_PRINTF_PATH	= 	./ft_printf/
MLX_PATH		= 	./mlx_linux/

SRCS_FILES    	= 	main.c convert.c error.c \
					sl_get_next_line.c sl_get_next_line_utils.c \
					mlx_free.c check_map.c check_map2.c \
					mlx_part1.c mlx_part2.c action.c

SRCS_OBJS		= 	$(SRCS_FILES:.c=.o)

LIBFTMAKE		= 	$(MAKE) -C $(LIBFT_PATH)
LIBFTFLAG		= 	-L$(LIBFT_PATH) -lft
FT_PRINTFMAKE	= 	$(MAKE) -C $(FT_PRINTF_PATH)
FT_PRINTFFLAG	= 	-L./$(FT_PRINTF_PATH) -lftprintf
MLXMAKE			= 	$(MAKE) -C $(MLX_PATH)
MLXFLAG			= 	-L$(MLX_PATH) -lmlx -Imlx_linux -lXext -lX11 -lm -L/usr/X11R6/lib
GITMLX			= 	git clone https://github.com/42Paris/minilibx-linux.git mlx_linux

all:			$(NAME)

$(MLX_PATH):
				$(GITMLX)

$(NAME):		$(MLX_PATH) $(SRCS_OBJS)
				$(LIBFTMAKE)
				$(FT_PRINTFMAKE)
				$(MLXMAKE)
				$(CC) $(CFLAGS) $(SRCS_OBJS) $(LIBFTFLAG) $(FT_PRINTFFLAG) $(MLXFLAG) -o $(NAME)

lib:
				$(LIBFTMAKE)

ft_printf:
				$(FT_PRINTFMAKE)

mlx:
				$(MLXMAKE)

.c.o:
				$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean:
				$(LIBFTMAKE) clean
				$(FT_PRINTFMAKE) clean
				$(MLXMAKE) clean
				$(RM) $(SRCS_OBJS)

fclean:			clean
				$(LIBFTMAKE) fclean
				$(FT_PRINTFMAKE) fclean
				$(RM) $(MLX_PATH)/libmlx.a
				$(RM) $(NAME) $(SRCS_OBJS)

re:				fclean all

.PHONY:			all clean fclean lib ft_printf mlx re
