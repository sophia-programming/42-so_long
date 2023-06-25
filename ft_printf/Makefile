# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/02 18:15:16 by oaoba             #+#    #+#              #
#    Updated: 2023/04/02 18:16:16 by oaoba            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

srcs	=	ft_printf.c\
			print_format_p.c\
			print_format_c.c\
			print_format_s.c\
			print_format_di.c\
			print_format_u.c\
			ft_numlen_hex.c\
			ft_smallhex.c\
			ft_largehex.c

objs	=	$(srcs:.c=.o)

CC		=	cc

RM		=	rm -f

CFLAGS	=	-Wall -Werror -Wextra

AR		= ar -r

all:		$(NAME)

$(NAME):	$(objs)
			$(AR) $(NAME) $(objs)

clean:
			$(RM) $(objs)
			
fclean:		clean
			$(RM) $(NAME) a.out
			
re:			fclean all

.PHONY:		all clean fclean re
