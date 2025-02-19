#minilibx / mlx pending to include!!!!!
NAME = miniRT

CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj

VPATH =	$(SRC_DIR):$(SRC_DIR)/

SOURCES =	

OBJECTS = $(SOURCES:%.c=$(OBJ_DIR)/%.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

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