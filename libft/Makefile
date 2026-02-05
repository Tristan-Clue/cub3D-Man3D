CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I$(INCLUDE)

NAME	= libft.a
INCLUDE	= include

LIBFT	= \
		  ft_atoi.c			ft_bzero.c			ft_calloc.c		ft_isalnum.c	\
		  ft_isalpha.c		ft_isascii.c		ft_isdigit.c	ft_isprint.c	\
		  ft_memchr.c		ft_memcmp.c			ft_memcpy.c		ft_memmove.c	\
		  ft_memset.c		ft_strchr.c			ft_strdup.c		ft_strlcat.c	\
		  ft_strlcpy.c		ft_strlen.c			ft_strncmp.c	ft_strnstr.c	\
		  ft_strrchr.c		ft_tolower.c		ft_toupper.c	ft_substr.c		\
		  ft_strjoin.c		ft_strtrim.c		ft_split.c		ft_itoa.c		\
		  ft_itoa_base.c	ft_uitoa_base.c		ft_strmapi.c	ft_striteri.c	\
		  ft_putchar_fd.c	ft_putstr_fd.c		ft_putendl_fd.c	ft_putnbr_fd.c	\
		  ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c	ft_lstlast.c	\
		  ft_lstiter.c		ft_lstadd_back.c	ft_lstdelone.c	ft_lstclear.c	\
		  ft_lstmap.c		ft_uitoa.c			ft_atoll.c		ft_strcmp.c		\
		  ft_atoi_base.c	ft_llabs.c			ft_abs.c		ft_fabs.c		\
		  ft_isspace.c		ft_qsort.c

PRINTF	= \
		  pf_char_string.c	pf_int.c	pf_ptr.c	pf_hex.c	pf_percent.c	\
		  ft_printf.c	ft_putnbrstr.c

GNL		= \
		  get_next_line.c	get_next_line_utils.c

LIBFT_DIR	= src/libft
PRINTF_DIR	= src/ft_printf
GNL_DIR		= src/get_next_line
OBJS_DIR	= build/

OBJS	= $(LIBFT:.c=.o)	\
		  $(PRINTF:.c=.o)	\
		  $(GNL:.c=.o)

BUILD_OBJS = $(addprefix $(OBJS_DIR), $(OBJS))

vpath %.c $(LIBFT_DIR) $(PRINTF_DIR) $(GNL_DIR)
vpath %.o $(OBJS_DIR)

GREEN	= \e[32m
CYAN	= \e[36m
WHITE	= \e[0m

.PHONY: all fclean clean re
.SILENT:

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	ar rcs $@ $(BUILD_OBJS)
	echo "Archiving $(GREEN)$(NAME)$(WHITE)..."

$(OBJS_DIR):
	mkdir build

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(addprefix $(OBJS_DIR), $@)
	echo "Compiling $(CYAN)$@$(WHITE)..."

fclean: clean
	rm -f $(NAME)
	echo "Removing $(GREEN)$(NAME)$(WHITE) files..."

clean:
	rm -rf $(OBJS_DIR)
	echo "Removing $(CYAN)object$(WHITE) files..."

re: fclean all
