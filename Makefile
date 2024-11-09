# Nom du programme
NAME = cub3d
NAME_BONUS = cub3d_bonus

# Dossier de sortie pour les fichiers objets
OBJ_DIR = obj/
OBJ_BONUS_DIR = obj_bonus/
SRCS_DIR = srcs/
SRCS_BONUS_DIR = srcs_bonus/


# Les différentes bibliothèques
LIBFT_DIR = libft
MLX_DIR = minilibx-linux
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a
MLX_FILE = libmlx.a
MLX_FLAG = -lX11 -lXext -lm
MLX_EX = $(MLX_LIB) $(MLX_FLAG)

# Headers et includes
HEADER = -I./includes \
 -I./libft/includes \
 -I./minilibx-linux \

# Options de compilation
CFLAGS = -Wall -Wextra -Werror -g3

# Commandes
CC = cc
RM = rm -rf

SRCS = $(shell find srcs/ -name "*.c" | sed 's@^srcs/@@' | tr '\n' ' ')
SRCS_BONUS = $(shell find srcs_bonus/ -name "*.c" | sed 's@^srcs_bonus/@@' | tr '\n' ' ')

MAKEFLAGS += --no-print-directory

TOTAL_FILES := $(words $(SRCS))
TOTAL_FILES_BONUS := $(words $(SRCS_BONUS))
CURRENT_INDEX := 0
CURRENT_INDEX_BONUS := 0

# Conversion des fichiers source en fichiers objets
OBJS = $(addprefix ${OBJ_DIR}, $(SRCS:.c=.o))
OBJS_BONUS = $(addprefix ${OBJ_BONUS_DIR}, $(SRCS_BONUS:.c=.o))
MLX_LIB = $(addprefix $(MLX_DIR), $(MLX_FILE))

# Cibles
all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "\n"

$(MLX):
	@echo "$(YELLOW)🔧 $(BLUE)$(BOLD)100% $(WHITE)$(BOLD)Compiling:$(WHITE)$(BOLD) $(MLX_FILE) $(RED)$(BOLD) $(MAGENTA)[ 31/ 31]$(RESET) \n"
	@$(MAKE) -C $(MLX_DIR) > /dev/null 2>&1

# Compilation du programme principal
$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(HEADER) $(LIBFT) $(MLX) $(MLX_FLAG)
	@echo "\n┗▷${BOLD}$(GREEN)『./$(NAME) Successfully created [✅]$(RESET)"

${OBJ_DIR}%.o: ${SRCS_DIR}%.c
	@mkdir -p $(dir $@)
	@$(eval CURRENT_INDEX=$(shell echo $$(($(CURRENT_INDEX)+1))))
	@$(eval PERCENT=$(shell echo $$(($(CURRENT_INDEX) * 100 / $(TOTAL_FILES)))))
	@printf "\r🔧 $(BLUE)$(BOLD)%3d%% $(WHITE)$(BOLD)Compiling:$(WHITE)$(BOLD) ${NAME}${RESET} $(RED)$(BOLD)%-50s $(MAGENTA)[%3d/%3d]$(RESET)" $(PERCENT) "$<" $(CURRENT_INDEX) $(TOTAL_FILES)
	@${CC} ${CFLAGS} ${HEADER} -c $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT) $(MLX) $(OBJS_BONUS)
	@$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(HEADER) $(LIBFT) $(MLX) $(MLX_FLAG)
	@echo "\n┗▷${BOLD}$(GREEN)『./$(NAME_BONUS) Successfully created [✅]$(RESET)"

${OBJ_BONUS_DIR}%.o: ${SRCS_BONUS_DIR}%.c
	@mkdir -p $(dir $@)
	@$(eval CURRENT_INDEX_BONUS=$(shell echo $$(($(CURRENT_INDEX_BONUS)+1))))
	@$(eval PERCENT=$(shell echo $$(($(CURRENT_INDEX_BONUS) * 100 / $(TOTAL_FILES_BONUS)))))
	@printf "\r🔧 $(BLUE)$(BOLD)%3d%% $(WHITE)$(BOLD)Compiling:$(WHITE)$(BOLD) ${NAME_BONUS}${RESET} $(RED)$(BOLD)%-50s $(MAGENTA)[%3d/%3d]$(RESET)" $(PERCENT) "$<" $(CURRENT_INDEX_BONUS) $(TOTAL_FILES_BONUS)
	@${CC} ${CFLAGS} ${HEADER} -c $< -o $@

# Nettoyage des fichiers objets
clean:
	@echo "$(BOLD) [ 🗑️ ] $(YELLOW)$(REVERSED)Cleaning up$(RESET)"
	@$(MAKE) clean -C $(LIBFT_DIR) > /dev/null 2>&1
	@$(MAKE) clean -C $(MLX_DIR) > /dev/null 2>&1
	@$(RM) -r $(OBJ_DIR) > /dev/null 2>&1
	@$(RM) -r $(OBJ_BONUS_DIR) > /dev/null 2>&1
	@echo "┗▷$(YELLOW)『$(ITALIC)./$(SRCS_DIR)'s$(RESET)$(YELLOW) object files cleaned』$(RESET)"

# Nettoyage complet
fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR) > /dev/null 2>&1
	@$(MAKE) clean -C $(MLX_DIR) > /dev/null 2>&1
	@$(RM) $(NAME) > /dev/null 2>&1
	@$(RM) $(NAME_BONUS) > /dev/null 2>&1
	@echo "┗▷$(YELLOW)『$(ITALIC)./$(NAME)'s$(RESET)$(YELLOW)'s executables cleaned』$(RESET)"

# Recompiler entièrement
re: fclean all

test: all
	valgrind --leak-check=full --show-leak-kinds=all -q ./$(NAME) ./maps/good/works.cub

testbad: re
	@for file in maps/bad/*.cub; do \
		echo "$(REVERSED) $$file $(RESET)"; \
		valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes -q ./cub3d $$file; \
		echo; \
	done;

testgood: re
	@for file in maps/good/*.cub; do \
		echo "$(REVERSED) $$file $(RESET)"; \
		valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes -q ./cub3d $$file; \
		echo; \
	done;

.PHONY: all clean fclean re bonus test

# Colors
RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;33m
BLUE := \033[0;34m
MAGENTA := \033[0;35m
CYAN := \033[0;36m
WHITE := \033[0;37m
RESET := \033[0m
BOLD := \033[1m
UNDERLINE := \033[4m
REVERSED := \033[7m
ITALIC := \033[3m
