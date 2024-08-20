CC 			:= gcc
NAME		:= so_long
CFLAGS		:= -Wextra -Wall -Werror
MLX42FLAGS	:= -ldl -lglfw -pthread -lm

MLX42		:= ./lib/MLX42/build/libmlx42.a
LIBFT		:= ./lib/libft/libft.a
INCLUDE 	:= -I ./includes

SRC			:= 
OBJ_DIR 	:= obj
# Generate object files inside obj/ folder
OBJ 		:= $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

all: $(NAME)

$(NAME): $(MLX42) $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX42) $(MLX42FLAGS) $(LIBFT)

$(LIBMLX):
	@$(MAKE) -C ./lib/MLX42

$(LIBFT):
	@$(MAKE) -C ./lib/libft

$(OBJ_DIR)/%.o: ./src/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $^

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
# Change to the libs directory and then execute fclean
	@$(MAKE) fclean -C ./MLX42
	@$(MAKE) fclean -C ./libft
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re