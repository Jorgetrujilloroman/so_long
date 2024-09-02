PROJECT := libft
CC := gcc
CFLAGS := -Werror -Wextra -Wall
NAME := libft.a

SRC = 		ft_isalpha.c ft_isdigit.c\
			ft_isalnum.c ft_isascii.c\
			ft_isprint.c ft_strlen.c \
			ft_memset.c ft_bzero.c \
			ft_memcpy.c ft_memmove.c \
			ft_strlcpy.c ft_strlcat.c \
			ft_toupper.c ft_tolower.c \
			ft_strchr.c ft_strrchr.c \
			ft_strncmp.c ft_memchr.c \
			ft_memcmp.c ft_strnstr.c \
			ft_atoi.c 	ft_calloc.c \
			ft_strdup.c ft_substr.c \
			ft_strjoin.c ft_strtrim.c \
			ft_split.c ft_itoa.c \
			ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c \
			get_next_line.c get_next_line_utils.c \
			ft_printf.c libftprintf.c

OBJ_DIR := obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

RED     := \033[31m
GREEN   := \033[32m
YELLOW  := \033[33m
BLUE 	:= \033[96m
RESET   := \033[0m

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME): $(OBJS)
	@echo "$(RED)------------------------------$(RESET)"
	@echo "Compiling $(YELLOW)$(PROJECT)$(RESET) with $(BLUE) get_next_line, ft_printf $(RESET) and flags: $(BLUE) $(CFLAGS)$(RESET)..."
	@ar rcs $(NAME) $(OBJS) $(PRINTF_OBJS) $(GNL_OBJS)
	@echo "$(GREEN)Done! ✅$(RESET)"
	@echo "$(RED)------------------------------$(RESET)"

all: $(NAME) $(PRINTF_OBJS) $(GNL_OBJS)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME) 

re: fclean all

.PHONY: all clean fclean re bonus
