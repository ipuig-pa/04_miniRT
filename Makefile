NAME = minirt

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

SRC_DIR = src
OBJ_DIR = obj

VPATH =	$(SRC_DIR):\
		$(SRC_DIR)/gc:\
		$(SRC_DIR)/math_utils:\
		$(SRC_DIR)/manage_env:\
		$(SRC_DIR)/parsing:\
		$(SRC_DIR)/parsing/check_print:\
		$(SRC_DIR)/rendering:\
		$(SRC_DIR)/transform:\
		$(SRC_DIR)/wdw_manage

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
			math_utils.c\
			init.c\
			num_check.c\
			print_err.c\
			clean_scene.c\
			check_read_file.c\
			ft_tofloat.c\
			parse_ambient.c\
			parse_camera.c\
			parse_color.c\
			parse_light.c\
			parse_vector.c\
			bonus_material.c\
			parse.c\
			exit_on_parsing.c\
			shape_cylinder.c\
			shape_plane.c\
			shape_sphere.c\
			tokens.c\
			viewport.c\
			ray_tracing.c\
			intersect.c\
			inside.c\
			normal.c\
			shading.c\
			phong.c\
			drawing.c\
			color.c\
			color2.c\
			transform.c\
			obj_transform.c\
			cam_transform.c\
			light_transform.c\
			matrix_utils.c\
			set_hooks.c\
			elem_hooks.c\
			obj_hooks.c\
			cam_hooks.c\
			light_hooks.c\
			rerender.c\
			main.c
#cyl_transform.c\

OBJECTS = $(SOURCES:%.c=$(OBJ_DIR)/%.o)

INC = inc

HEADERS =	$(INC)/minirt.h\
			$(INC)/color.h\
			$(INC)/env.h\
			$(INC)/gc.h\
			$(INC)/hook.h\
			$(INC)/linalg.h\
			$(INC)/parser.h\
			$(INC)/ray.h\
			$(INC)/scene.h\
			$(INC)/transform.h

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

#MLX_FLAGS = -lmlx -lXext -lX11
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
#MLX_DIR = minilibx-linux
MLX_DIR = minilibx_macos
MLX = $(MLX_DIR)/libmlx.a

all : $(NAME)

$(NAME) : $(SOURCES) $(HEADERS) $(OBJ_DIR) $(MLX) $(OBJECTS) $(LIBFT)
	cc $(CFLAGS) $(OBJECTS) -L$(MLX_DIR) -L$(LIBFT_DIR) $(MLX_FLAGS) -lft -lm -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c $(HEADERS)
	cc $(CFLAGS) -I$(LIBFT_DIR) -Iinc -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	@git clone https://github.com/U-Mina/minilibx_openGL.git $(MLX_DIR)
	make -C $(MLX_DIR)

clean : 
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)
#make clean -C $(MLX_DIR)
	rm -rf $(MLX_DIR)

fclean : clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re : fclean all

.PHONY : all clean fclean re mlx