NAME = cub3D

SRCS_DIR = srcs/
OBJ_DIR = obj/
INC_DIR = includes/
LIB_DIR = libs/

INCLUDES = -I$(INC_DIR)

CC = gcc
FLAGS = -g

MLX_DIR = $(LIB_DIR)/mlx
MLX_FLAGS = -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
LIBFT_DIR = $(LIB_DIR)/libft
LIBFT_FLAGS = -L $(LIBFT_DIR) -lft

FILES = cub3d \
		colors \
		render \
		errors \
		parser \
		preparation \
		controls \
		raycasting


SRCS_FILES = $(addsuffix .c, $(addprefix $(SRCS_DIR), $(FILES)))

OBJ_FILES = $(addsuffix .o, $(addprefix $(OBJ_DIR), $(FILES)))


all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ_FILES)
	@make -C $(MLX_DIR)
	@make -C $(LIBFT_DIR)
	@$(CC) -o $(NAME) $(INCLUDES) $(OBJ_FILES) $(LIBFT_FLAGS) $(MLX_FLAGS) -fsanitize=address

$(OBJ_FILES): $(OBJ_DIR)%.o : $(SRCS_DIR)%.c
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_FILES)
	@rm -f screenshot.bmp
	@make -C $(LIBFT_DIR) clean
	#@make -C $(MLX_DIR) clean
	@echo "Project has been cleaned"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	#@make -C $(MLX_DIR) clean
	@echo "$(NAME) and Libs has been removed"

re: fclean all

run: re 
	./cub3D map.cub
