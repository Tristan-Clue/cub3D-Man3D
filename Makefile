NAME		= cub3D

CC			= cc
CFLAGS		= -Wextra -Werror -Wall -g3 -O3
IFLAGS		= -I$(INCLUDE) -I$(LIBFT_LIB) -I$(LIBMLX_LIB)
MLX_FLAGS	= -L/usr/lib -lXext -lX11 -lm -lz
MATH		= -lm

LIBFT		= $(LIBFT_DIR)/libft.a
LIBFT_DIR	= libft
INCLUDE		= include

LIBMLX		= mlx_linux/libmlx_Linux.a

ARCHIVE		= $(LIBFT) $(LIBMLX)

LIBFT_LIB	= libft/include
LIBMLX_LIB	= mlx_linux

OBJS_DIR	= build/
SRCS_DIR		= src/

SRC		= \
			main.c		error.c		cleanup.c					\
			color.c	extract_xpm.c	destroy.c					\
			event/detect_input.c	event/event_camera.c		\
			event/event_loop.c		event/movement.c			\
			event/update_data.c		event/detect_input_utils.c	\
			init/flood_fill.c		init/parse_layout.c			\
			init/parse_player_pos.c	init/parse_tex_utility.c	\
			init/init.c				init/parse_map.c			\
			init/parse_tex.c									\
			render/render_background.c							\
			render/render.c		render/ray_calculation.c		\
			debug/debug.c		animation/render_anim.c

OBJS_DIR	= build/


SRCS_FILES	= $(addprefix $(SRCS_DIR), $(SRCS))
OBJS		= $(SRC:.c=.o)
BUILD_OBJS	= $(addprefix $(OBJS_DIR), $(OBJS))

vpath %.c 	$(SRCS_DIR)
vpath %.o	$(OBJS_DIR)

GREEN	= \e[32m
CYAN	= \e[36m
WHITE	= \e[0m

.PHONY: all fclean clean re
#.SILENT:

all : $(OBJS_DIR) $(NAME)

$(NAME): $(LIBFT) $(LIBMLX) $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) $(BUILD_OBJS) $(ARCHIVE) $(MLX_FLAGS) $(MATH) -o $(NAME)
	echo "Compiling $(GREEN)$(NAME)$(WHITE)..."

$(OBJS_DIR):
	mkdir	$(OBJS_DIR)
	mkdir	$(OBJS_DIR)/render
	mkdir	$(OBJS_DIR)/init
	mkdir	$(OBJS_DIR)/event
	mkdir	$(OBJS_DIR)/debug
	mkdir	$(OBJS_DIR)/animation

$(LIBFT):
	echo "Compiling libft functions..."
	make --no-print-directory -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $(addprefix $(OBJS_DIR), $@)
	echo "Compiling $(CYAN)$@$(WHITE)..."

$(LIBMLX):
	echo "Compiling mlxlib functions..."
	make --no-print-directory -C $(LIBMLX_LIB)

fclean: clean
	rm -f $(NAME)
	echo "Removing $(GREEN)$(NAME)$(WHITE) files..."

clean:
	make -C $(LIBFT_DIR) fclean
	make -C $(LIBMLX_LIB) clean
	rm -rf $(OBJS_DIR)
	echo "Removing $(CYAN)object$(WHITE) files..."

re: fclean all
