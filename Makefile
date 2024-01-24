NAME := fractol

# Necessities
CC := cc

LFT_DIR := libft
LIBFT := ft

INC_DIR := $(addprefix -I, includes $(LFT_DIR)/includes)
INCLUDE := fractol.h
INCLUDES = $(addprefix includes/, $(INCLUDE));

CFLAGS := -Wall -Wextra -Werror $(INC_DIR) -g3 -fsanitize=address,undefined -lm

SRC := main.c
SRCS := $(addprefix srcs/, $(SRC))

# Rules
all: $(NAME)

$(NAME): $(INCLUDES) $(SRCS)
	@make -C libft

clean:

fclean:

re: fclean all