#minilibx / mlx pending to include!!!!!
NAME = miniRT

CFLAGS = -Wall -Wextra -Werror
LDFLAGS = LDFLAGS = -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -ldl -lm -g

SRC_DIR = src
OBJ_DIR = obj

VPATH =	$(SRC_DIR):$(SRC_DIR)/

SOURCES =	

OBJECTS = $(SOURCES:%.c=$(OBJ_DIR)/%.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX = MLX42/build/libmlx42.a

all : $(NAME)

$(MLX):
		@git clone https://github.com/codam-coding-college/MLX42.git
		@cd MLX42 && cmake -B build && cmake --build build -j4

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	cc $(CFLAGS) -I$(LIBFT_DIR) -Imxl -Iinc -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME) : $(MLX) $(OBJ_DIR) $(OBJECTS) $(LIBFT)
	cc $(CFLAGS) $(OBJECTS) $(MLX) -L$(LIBFT_DIR) -lft -o $(NAME) $(LDFLAGS)

clean : 
	rm -rf $(OBJ_DIR)
	rm -rf MLX42
	make clean -C $(LIBFT_DIR)

fclean : clean
	rm -f $(NAME) $(MLX)
	make fclean -C $(LIBFT_DIR)

re : fclean all

.PHONY : all clean fclean re