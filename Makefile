# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-bouz <ael-bouz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/15 11:32:24 by ael-bouz          #+#    #+#              #
#    Updated: 2024/04/19 15:52:53 by ael-bouz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS				=	main.c \
						utils/ft_bzero.c utils/ft_calloc.c utils/ft_split.c utils/free_utils.c \
						utils/ft_substr.c utils/ft_atoi.c utils/ft_htoi.c utils/utls.c\
						get_next_line/get_next_line_utils.c \
						get_next_line/get_next_line.c \
						matrix_creation.c map_parsing.c filename_validation.c map_drawing.c bresenham_functions.c \
						get_file_dimensions.c

OBJS 				=	$(SRCS:.c=.o)

NAME				= 	fdf
CC					= 	cc
CFLAGS				= 	-Wall -Wextra -Werror
MLX					=	-I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
RM					= 	rm -f

all:	$(NAME)

test:
	echo $(TITLE)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(MLX) $(OBJS) -o $(NAME)
	@make clean

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

re: fclean all

clean:
	@rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

.PHONY : all bonus clean fclean re
