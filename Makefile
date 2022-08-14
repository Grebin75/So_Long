# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/14 10:36:45 by hcoutinh          #+#    #+#              #
#    Updated: 2022/08/14 12:49:57 by hcoutinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 			= gcc
CFLAGS		= -g -Wall -Wextra -Werror -fsanitize=address
RM			= rm -fr
MLX			= mlx_linux/mlx_Linux.a
NAME		=	so_long

SRCS		=	so_long.c windowhandler.c hookhandler.c
OBJS		= $(SRCS:.c=.o)


all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME):	mlx_linux/mlx_Linux.a $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)


$(MLX):
	make -C mlx_linux

clean:
			$(RM)	$(OBJS)
			make clean -C mlx_linux
			$(RM) a.out
			
fclean:	clean
			$(RM)	$(NAME)	
re:	fclean all

.PHONY: fclean all re clean