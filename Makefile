NAME		= Man3D

CC			= cc
CFLAGS		= -Wextra -Werror -Wall -g3 -O3
IFLAGS		= -I$(INCLUDE)
MLX_FLAGS	= -L/usr/lib -lXext -lX11 -lm -lz

LIBFT		= $(LIBFT_DIR)/libft.a
LIBFT_DIR	= libft
INCLUDE		= include

LIBMLX		= mlx_linux/libmlx_Linux.a

LIBFT_LIB	= libft/includes
LIBMLX_LIB	= mlx_linux

OBJS_DIR	= build/
SRC_DIR		= src/

SRC		= \
			main.c	error.c		key_events.c	draw_fractol.c	panning.c	\
			zooming.c		mouse.c		utils.c		color.c		newton.c	\
			init.c

OBJS_DIR	= build/
SRCS_DIR	= build/

SRCS_FILES	= $(addprefix $(SRCS_DIR), $(SRCS))
OBJS		= $(SRCS:.c=.o)
BUILD_OBJS	= $(addprefix $(OBJS_DIR), $(OBJS))

vpath %.c 	$(SRCS_DIR)
vpath %.o	$(OBJS_DIR)

GREEN	= \e[32m
CYAN	= \e[36m
WHITE	= \e[0m

.PHONY: all fclean clean re
.SILENT:

all : $(NAME)

$(NAME): $(LIBFT) $(LIBMLX) $(OBJS_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) $(BUILD_OBJS) $(MLX_FLAGS) -o $(NAME) $(LIBFT) $(LIBMLX)
	echo "Compiling $(GREEN)$(NAME)$(WHITE)..."

$(OBJS_DIR):
	mkdir	$(OBJS_DIR)
	mkdir	$(OBJS_DIR)/render
	mkdir	$(OBJS_DIR)/init

$(LIBFT):
	echo "Compiling libft functions..."
	make --no-print-directory -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(IFLAGS) $(MLX_FLAGS) -c $< -o $(addprefix $(OBJS_DIR), $@)
	echo "Compiling $(CYAN)$@$(WHITE)..."

$(LIBMLX):
	echo "Compiling mlxlib functions..."
	make --no-print-directory -C $(LIBMLX_LIB)

fclean: clean
	rm -f $(NAME)
	echo "Removing $(GREEN)$(NAME)$(WHITE) files..."

clean:
	make -C $(LIBFT_DIR) fclean
	rm -rf $(OBJS_DIR)
	echo "Removing $(CYAN)object$(WHITE) files..."

re: fclean all
