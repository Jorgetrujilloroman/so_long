PROJECT 	:= so_long 
CC 			:= gcc
NAME		:= so_long
CFLAGS		:= -Wextra -Wall -Werror
MLX42FLAGS	:= -ldl -lglfw -pthread -lm

MLX42		:= ./lib/MLX42/build/libmlx42.a
LIBFT		:= ./lib/libft/libft.a
INCLUDE 	:= -I ./includes -I ./lib/MLX42/include -I .lib/get_next_line

SRC			:= ./src/so_long.c \
				./src/utils.c \
				./src/map_checker.c
OBJ_DIR 	:= obj
# Generate object files inside obj/ folder
OBJ 		:= $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

RED     := \033[31m
GREEN   := \033[32m
YELLOW  := \033[33m
BLUE 	:= \033[96m
RESET   := \033[0m

all: $(NAME)

$(NAME): $(MLX42) $(LIBFT) $(OBJ)
	@echo "Compiling $(YELLOW)$(PROJECT)$(RESET) with $(BLUE)$(CFLAGS)$(RESET)..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX42) $(MLX42FLAGS) $(LIBFT)
	@echo "$(GREEN)Done! ✅$(RESET)"
	@echo "$(RED)------------------------------$(RESET)"

$(LIBFT):
	@$(MAKE) --no-print-directory -C ./lib/libft

$(OBJ_DIR)/%.o: ./src/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $^

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) --no-print-directory clean -C ./lib/libft

fclean: clean
# Change to the libs directory and then execute fclean
	@rm -rf $(NAME)
	@$(MAKE) --no-print-directory fclean -C ./lib/libft

re: clean all

.PHONY: all, clean, fclean, re