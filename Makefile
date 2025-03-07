#minilibx / mlx pending to include!!!!!
NAME = minirt

CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj

VPATH =	$(SRC_DIR):$(SRC_DIR)/gc:$(SRC_DIR)/linear_algebra:$(SRC_DIR)/manage_env:$(SRC_DIR)/parsing:$(SRC_DIR)/parsing/err_check_print:$(SRC_DIR)/rendering:$(SRC_DIR)/wdw_manage

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
			clean_err.c\
			num_check.c\
			print_err.c\
			check_read_file.c\
			ft_tofloat.c\
			parse_ambient.c\
			parse_camera.c\
			parse_color.c\
			parse_light.c\
			parse_vector.c\
			parse.c\
			shape_cylinder.c\
			shape_plane.c\
			shape_sphere.c\
			tokens.c\
			ray_tracing.c\
			intersect.c\
			normal.c\
			shading.c\
			drawing.c\
			transform.c\
			matrix_utils.c\
			material.c\
			hooks.c\
			hooks_2.c\
			main.c

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
	cc $(CFLAGS) $(OBJECTS) -L$(MLX_DIR) -L$(LIBFT_DIR) $(MLX_FLAGS) -lft -lm -o $(NAME)

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