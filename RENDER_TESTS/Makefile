#minilibx / mlx pending to include!!!!!
NAME = minirt

CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj

VPATH =	$(SRC_DIR):$(SRC_DIR)/gc:$(SRC_DIR)/linear_algebra:$(SRC_DIR)/manage_env:$(SRC_DIR)/rendering:

SOURCES =	gc_malloc_free.c\
			gc_error.c\
			gc_list_utils.c\
			gc_itoa.c\
			gc_split.c\
			gc_strdup.c\
			gc_strjoin.c\
			gc_strtrim.c\
			gc_substr.c\
			linalg_utils.c\
			init.c\
			ray_tracing.c\
			intersect.c\
			normal.c\
			shading.c\
			drawing.c\
			main_render.c

OBJECTS = $(SOURCES:%.c=$(OBJ_DIR)/%.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

#MLX_FLAGS = -lmlx -lXext -lX11
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
#MLX_DIR = minilibx-linux 
MLX_DIR = minilibx_macos
MLX = $(MLX_DIR)/libmlx.a

all : $(NAME)

$(NAME) : $(OBJ_DIR)  $(MLX) $(OBJECTS) $(LIBFT)
	cc $(CFLAGS) $(OBJECTS) -L$(MLX_DIR) -L$(LIBFT_DIR) $(MLX_FLAGS) -lft -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	cc $(CFLAGS) -I$(LIBFT_DIR) -Iinc -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX) :
	make -C $(MLX_DIR)

clean : 
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

fclean : clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re : fclean all

.PHONY : all clean fclean re