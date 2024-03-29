# Necessities
CC := cc
CFLAGS = -Wextra -Werror -Wall -g3

# OS-specification
OS := $(shell uname)

Dar = Darwin

Lin = Linux

ifeq (${OS}, ${Dar})
	BUILD_DIR := minilibx_opengl_20191021
	MLX := mlx
	CFLAGS += -L$(BUILD_DIR) -I$(BUILD_DIR) -l$(MLX) -framework OpenGL -framework Appkit -Llibft -Ilibft/includes -lft -L/usr/lib -lm
else ifeq (${OS}, ${Lin})
	BUILD_DIR := minilibx_linux
	MLX := mlx_Linux
	CFLAGS += -L$(BUILD_DIR) -I$(BUILD_DIR) -l$(MLX) -L/usr/lib -lXext -lX11 -lm -lz -Llibft -Ilibft/includes -lft
else
    $(error Idk, man. Doesn't look like something I was BUILT to deal with ;3)
endif

# PROJECT
NAME := fractol

SRC := main.c coloring.c utils.c render.c hooks.c init.c
SRC_DIR := srcs
SRCS := $(addprefix $(SRC_DIR)/, $(SRC))

INC := fractol.h
INC_DIR := includes
INCLUDE := $(addprefix $(INC_DIR)/, $(INC))
all: $(NAME)

$(NAME): $(SRCS) $(INCLUDE)
	@make -C $(BUILD_DIR)
	make -C libft 
	$(CC) -o $(NAME) -I$(INC_DIR) $(SRCS) $(CFLAGS)  

clean:
	@make -C $(BUILD_DIR) clean
	make -C libft clean

fclean:
	@make -C $(BUILD_DIR) clean
	rm -rf $(BUILD_DIR)/lib$(MLX).a
	make -C libft fclean
	rm -rf $(NAME)

re: fclean all
