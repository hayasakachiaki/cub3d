NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -Ilibft -Ift_printf -Iget_next_line
AR = ar rcs
RM = rm -f

DIR_LIBFT  = libft
DIR_PRINTF = ft_printf
DIR_GNL    = get_next_line

LIB_SRC_NAMES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
                ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
                ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
                ft_calloc.c ft_strdup.c ft_toupper.c ft_tolower.c \
                ft_strchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
                ft_strnstr.c ft_atoi.c ft_strrchr.c ft_substr.c \
                ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
                ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
                ft_putendl_fd.c ft_putnbr_fd.c ft_isspace.c ft_ishexdigit.c \
                ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
                ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
                ft_lstiter.c ft_lstmap.c

PF_SRC_NAMES = ft_printf.c ft_address.c ft_hex.c \
               ft_putchar.c ft_putnbr.c ft_string.c ft_unsigned.c

GNL_SRC_NAMES = get_next_line.c get_next_line_utils.c

LIB_SRCS = $(addprefix $(DIR_LIBFT)/, $(LIB_SRC_NAMES))
PF_SRCS  = $(addprefix $(DIR_PRINTF)/, $(PF_SRC_NAMES))
GNL_SRCS = $(addprefix $(DIR_GNL)/, $(GNL_SRC_NAMES))

SRCS = $(LIB_SRCS) $(PF_SRCS) $(GNL_SRCS)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
