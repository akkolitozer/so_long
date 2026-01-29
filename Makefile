# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/20 16:34:37 by hulescur          #+#    #+#              #
#    Updated: 2026/01/28 15:13:17 by hulescur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/ft_putstr.c libft/ft_putnbr.c \
		libft/ft_putchar.c libft/ft_calloc.c \

GNL = 	gnl/get_next_line.c gnl/get_next_line_utils.c \

SRCS =	$(LIBFT) $(GNL) src/main.c src/map_parser.c src/map_parser2.c \
		src/map_open.c src/minilx_init.c src/ft_strtrim.c \
		src/minilx_rendermap.c src/minilx_renderplayer.c \
		src/player_movement.c src/interactions.c \
		src/cleanup.c \

SRCS_BONUS = $(LIBFT) $(GNL) \
			src/main.c src/map_parser2.c src/map_open.c src/ft_strtrim.c \
			src/minilx_rendermap.c src/minilx_renderplayer.c src/cleanup.c \
			src_bonus/dead_bonus.c src_bonus/enemy_moves_bonus.c \
			src_bonus/enemy_bonus.c src_bonus/interactions_bonus.c \
			src_bonus/minilx_init_bonus.c src_bonus/player_movement_bonus.c \
			src_bonus/map_parser_bonus.c \

CC = cc 
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
X11_LIB = -lXext -lX11 -lm -lz
MLXLIB = -Lminilx -lmlx

NAME = so_long
NAME_BONUS = so_long_bonus
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

bonus : $(NAME_BONUS)

$(NAME): $(OBJS)
	make -C minilx
	$(CC) $(CFLAGS) $(OBJS) $(MLXLIB) $(X11_LIB) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	make -C minilx
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(MLXLIB) $(X11_LIB) -o $(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Iminilx -O3 -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

bonus:  $(NAME_BONUS)

bonus_re: fclean bonus

.PHONY: all clean fclean re bonus bonus_re
