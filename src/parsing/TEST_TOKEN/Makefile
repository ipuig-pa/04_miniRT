# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/22 15:04:06 by ewu               #+#    #+#              #
#    Updated: 2025/02/22 15:09:33 by ewu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minirt

CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj

VPATH =	$(SRC_DIR):$(SRC_DIR)/gc:$(SRC_DIR)

SOURCES =	gc_malloc_free.c\
			gc_error.c\
			gc_list_utils.c\
			gc_itoa.c\
			gc_split.c\
			gc_strdup.c\
			gc_strjoin.c\
			gc_strtrim.c\
			gc_substr.c\
			tokens.c\
			valid_read_file.c\
			print_err.c\
			test_parse.c

OBJECTS = $(SOURCES:%.c=$(OBJ_DIR)/%.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

#MLX_FLAGS = -lmlx -lXext -lX11
#MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
#MLX_DIR = minilibx-linux 
#MLX_DIR = minilibx_macos
#MLX = $(MLX_DIR)/libmlx.a

all : $(NAME)

$(NAME) : $(OBJ_DIR) $(OBJECTS) $(LIBFT)
	cc $(CFLAGS) $(OBJECTS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	cc $(CFLAGS) -I$(LIBFT_DIR) -Iinc -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean : 
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

fclean : clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re : fclean all

.PHONY : all clean fclean re