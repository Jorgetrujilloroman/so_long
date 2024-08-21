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
			ft_putendl_fd.c ft_putnbr_fd.c

BONUS_SRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c ft_lstiter_bonus.c \
			ft_lstmap_bonus.c

OBJ_DIR := obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
BONUS_OBJS = $(addprefix $(OBJ_DIR)/, $(BONUS_SRC:.c=.o))

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
	@echo "Compiling $(YELLOW)$(PROJECT)$(RESET) with $(BLUE)$(CFLAGS)$(RESET)..."
	@ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)Done! ✅$(RESET)"
	@echo "$(RED)------------------------------$(RESET)"

all: $(NAME)

bonus: $(NAME) $(BONUS_OBJS)
	@echo "$(RED)------------------------------$(RESET)"
	@echo "Compiling $(YELLOW)$(PROJECT) Bonus$(RESET)..."
	@ar rcs $(NAME) $(BONUS_OBJS)
	@echo "$(GREEN)Done! ✅$(RESET)"
	@echo "$(RED)------------------------------$(RESET)"

clean:
	@rm -rf $(OBJ_DIR) *.out *.gch *.tmp

fclean: clean
	@rm -rf $(NAME) 

re: fclean all

.PHONY: all clean fclean re bonus
