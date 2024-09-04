PROJECT := MLX42
NAME		:= libmlx42.a
MLX42_BUILD_DIR := build
INCLUDE_DIR	:= include

CFLAGS :=	-Wextra -Wall -Werror -Wunreachable-code -Wno-char-subscripts -Wno-sign-compare \
			-DLODEPNG_NO_COMPILE_ANCILLARY_CHUNKS -DLODEPNG_NO_COMPILE_ENCODER

RED     := \033[31m
GREEN   := \033[32m
YELLOW  := \033[33m
BLUE 	:= \033[96m
RESET   := \033[0m

all: $(NAME)

$(NAME):
	@echo "Compiling $(YELLOW)$(PROJECT)$(RESET)..."
	@cmake -B build
	@cmake --build build -j4
	@echo "$(GREEN)Done! ✅$(RESET)"
	@echo "$(RED)------------------------------$(RESET)"

fclean:
	@rm -f $(NAME)
	@rm -rf $(MLX42_BUILD_DIR)

.PHONY: all fclean