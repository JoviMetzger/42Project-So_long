NAME 			= so_long
MAP				= ./graphics/maps/map3.ber

# COMPILATION FLAGS
CC 				= gcc
CFLAGS 			= -Wall -Werror -Wextra -g #-fsanitize=address
MLXFLAGS		= -I include -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit

# LIBRARIES
LIBFT_PATH		= ./libraries/libft
LIBFT 			= $(LIBFT_PATH)/libft.a

MINILIBX_PATH	= ./libraries/minilibx42
MINILIBX		= $(MINILIBX_PATH)/libmlx42.a

SO_LONG_PATH	= ./src
SO_LONG			= $(SO_LONG_PATH)/so_long.a

# TEMPORARY FIX DO NOT USE
SRC				:= ./src/so_long.c ./src/make_window.c ./src/render_map.c ./src/check_map_valid.c ./src/keyBoard_hooks.c ./src/utils.c
OBJ				:= $(SRC:.c=.o)

# Colours
BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m

all: 			$(NAME)

# MAKE LIBFT & MINILIBX AND CP TO NAME
$(NAME): 		$(LIBFT) $(MINILIBX) $(SO_LONG)
	@$(CC) $(CFLAGS) -o $(NAME) $(LIBFT) $(SO_LONG) $(MINILIBX) $(MLXFLAGS)
	@echo "$(WHITE)$(BOLD)Done Compiling Program!$(RESET)"

$(LIBFT):
	@echo "$(YELLOW)$(BOLD)Compiling Libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_PATH)
	@echo "$(GREEN)$(BOLD)Done$(RESET)"

$(MINILIBX):
	@echo "$(YELLOW)$(BOLD)Compiling Minilibx...$(RESET)"
	@$(MAKE) -C $(MINILIBX_PATH)
	@echo "$(GREEN)$(BOLD)Done$(RESET)"

	@echo "$(YELLOW)$(BOLD)Compiling So_long...$(RESET)"
$(SO_LONG): $(SRC) $(OBJ)
	@$(MAKE) -C $(SO_LONG_PATH)
	@echo "$(GREEN)$(BOLD)Done$(RESET)"

# Executest the program
open: $(NAME)
	@echo "$(MAGENTA)$(BOLD)Opening Window...$(RESET)"
	@./$(NAME) $(MAP)
	@echo "$(BLACK)$(BOLD)Window Closed$(RESET)"

# CLEAN
clean:
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(MINILIBX_PATH) clean
	@$(MAKE) -C $(SO_LONG_PATH) clean
	@rm -f $(OBJ_PATH)
	@echo "$(RED)Cleaning Done$(RESET)"

fclean:
	@$(MAKE) -C $(MINILIBX_PATH) fclean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) -C $(SO_LONG_PATH) fclean
	@rm -f $(NAME)
	@echo "$(RED)fcleaning Done$(RESET)"

re: 			fclean all

.PHONY: 		all clean fclean re open
# .DEFAULT_GOAL:= open