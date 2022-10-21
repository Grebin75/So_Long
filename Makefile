SRCS		= $(SRCS_DIR)/so_long.c \
			$(SRCS_DIR)/get_next_line.c \
			$(SRCS_DIR)/get_next_line_utils.c \
			$(SRCS_DIR)/mapchecker.c \
			$(SRCS_DIR)/maputils1.c \
			$(SRCS_DIR)/maputils2.c \
			$(SRCS_DIR)/generalutils.c \
			$(SRCS_DIR)/setgame.c \
			$(SRCS_DIR)/key.c \



SRCS_DIR	= srcs

OBJS		= $(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.o))

OBJS_DIR 	= objs

MLX			= mlx_linux/libmlx_Linux.a

PRINTF		= printf/libftprintf.a

CC 			= clang
CFLAGS		= -g -Wall -Wextra -Werror #-fsanitize=address
RM			= rm -fr
NAME		=	so_long

all: $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	mkdir -p objs
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME):	$(PRINTF) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -Lprintf -lftprintf -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)


$(MLX):
	make -C mlx_linux

$(PRINTF):
	make -C printf

clean:
			$(RM)	$(OBJS)
			make clean -C mlx_linux

fclean:	clean
			$(RM)	$(NAME) $(OBJS_DIR)
re:	fclean all

.PHONY: fclean all re clean
