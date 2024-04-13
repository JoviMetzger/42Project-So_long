NAME			= so_long
MAP				= ./graphics/maps/map3.ber

# Compiler and flags
CC				= cc
CFLAGS			= -Wall -Wextra
CFLAGS			+= -Werror
CFLAGS			+= -g -fsanitize=address

# Libraries
LIBFT_PATH		= ./libraries/libft
LIBFT			= $(LIBFT_PATH)/libft.a

MLX42_HEADER	= -I include -lglfw -I $(MLX42_PATH)/include/MLX42/
MLX42_PATH		= ./libraries/mlx42
MLX42			= $(MLX42_PATH)/build/libmlx42.a

# Source files
SRCS			= ./src/so_long.c \
					./src/make_window.c \
					./src/render_map.c \
					./src/check_map_valid.c \
					./src/keyBoard_hooks.c \
					./src/utils.c

SRC_DIR			= src
OBJ_PATH		= obj
OBJ				= $(addprefix $(OBJ_PATH)/, $(notdir $(SRCS:.c=.o)))

# Colors
PINK			= \033[35m
BLUE			= \033[34;1m
GREEN			= \033[32;1m
CORAL			= \033[38;2;255;127;80m
BOLD			= \033[1m
ITALIC			= \033[3m
UNDER			= \033[4m
RESET			= \033[0m

# Rule for compiling object files
$(OBJ_PATH)/%.o: $(SRC_DIR)/%.c
			@mkdir -p $(OBJ_PATH)
			@$(CC) $(CFLAGS) -c -o $@ $<

# Targets
all:	$(NAME)

$(NAME):	$(LIBFT) $(MLX42) $(OBJ)
			@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX42) $(MLX42_HEADER) -lm -o $(NAME)
			@echo "$(CORAL) $(UNDER) $(BOLD) $(ITALIC)   ✨Compilation Done✨      $(RESET)"

$(LIBFT):
		@$(MAKE) -C $(LIBFT_PATH)
		@echo "$(BLUE)$(BOLD) --- Compiling Libft Done --- $(RESET)"

$(MLX42):
		@cd $(MLX42_PATH) && cmake -B build && cmake --build build -j4
		@echo "$(BLUE)$(BOLD) --- Compiling Minilibx Done --- $(RESET)"

# Executest the program
open: $(NAME)
		@echo "$(PINK)$(BOLD) Opening Window... $(RESET)"
		@./$(NAME) $(MAP)
		@echo "$(PINK)$(BOLD) Window Closed $(RESET)"

# Clean
clean:
		@$(MAKE) clean -C $(LIBFT_PATH)
		@rm -rf $(MLX42_PATH)/build
		@rm -rf $(OBJ_PATH)
		@echo "$(GREEN) $(ITALIC) ✅ Cleaned object files ✅$(RESET)"

fclean: clean
		@$(MAKE) fclean -C $(LIBFT_PATH)
		@rm -rf $(OBJ_PATH)
		@rm -rf $(NAME)
		@echo "$(GREEN) $(ITALIC)   ✅ Cleaned executer ✅$(RESET)"

re: fclean all

.PHONY: all clean fclean re open