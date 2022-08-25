# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/14 10:36:45 by hcoutinh          #+#    #+#              #
#    Updated: 2022/08/25 15:35:22 by hcoutinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 			= gcc
CFLAGS		= -g -Wall -Wextra -Werror #-fsanitize=address
RM			= rm -fr
MLX			= mlx_linux/libmlx_Linux.a
NAME		=	so_long
PRINTF 		= ft_printf/libftprintf.a

SRCS		= so_long.c windowhandler.c hookhandler.c mapchecker.c\
			./Getnextline/get_next_line_utils.c  \
			./Getnextline/get_next_line.c 		\
			createimgs.c \
			
OBJS		= $(SRCS:.c=.o)


all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME):	$(PRINTF) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -Lft_printf -lftprintf -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)


$(MLX):
	make -C mlx_linux

$(PRINTF):
	make -C printf

clean:
			$(RM)	$(OBJS)
			make clean -C mlx_linux
			
fclean:	clean
			$(RM)	$(NAME)	
re:	fclean all

.PHONY: fclean all re clean