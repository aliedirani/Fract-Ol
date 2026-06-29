NAME		= fractol
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
MLX_DIR		= MLX42
MLX_BUILD	= $(MLX_DIR)/build
MLX_LIB		= $(MLX_BUILD)/libmlx42.a
SRCS		= main.c init.c controls.c render.c fractal_calc.c \
			  events.c events_utils.c autoplay.c utils.c parse.c cleanup.c \
			  color.c color_palettes.c fractol_help.c
OBJS		= $(SRCS:.c=.o)
INCLUDES	= -I. -I$(MLX_DIR)/include

ifeq ($(OS),Windows_NT)
UNAME_S		= Windows
else
UNAME_S		:= $(shell uname -s)
endif

ifeq ($(UNAME_S),Darwin)
LIBS		= -L$(MLX_BUILD) -lmlx42 -lglfw -lm -pthread \
			  -framework Cocoa -framework OpenGL -framework IOKit
else
LIBS		= -L$(MLX_BUILD) -lmlx42 -lglfw -ldl -lm -pthread
endif

all: $(NAME)

bonus: all

$(MLX_LIB):
	cmake -S $(MLX_DIR) -B $(MLX_BUILD)
	cmake --build $(MLX_BUILD) -j4

$(NAME): $(MLX_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c fractol.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -rf $(MLX_BUILD)

re: fclean all

.PHONY: all bonus clean fclean re
