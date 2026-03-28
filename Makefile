NAME        = cub3d
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g

MLX_DIR     = ./minilibx-linux
MLX_LIB     = $(MLX_DIR)/libmlx.a
MLX_FLAGS   = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lbsd

# MLX_FLAGS = -L./usr/local/lib -lmlx -framework OpenGL -framework AppKit

LIBFT_DIR   = ./libft
LIBFT_LIB   = $(LIBFT_DIR)/libft.a
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft

INCLUDES    = -I./includes -I$(MLX_DIR) -I$(LIBFT_DIR) \
	      -I$(LIBFT_DIR)/ft_printf -I$(LIBFT_DIR)/get_next_line \
		  -I./usr/local/include

SRC_DIR     = srcs
SRC_FILES   = main.c key_hooks.c render.c draw.c move.c rotate.c \
	      init_ray.c raycast_utils.c time_utils.c \
	      parser_texture.c parser_fc.c parser_fc_utils.c parser_entry.c \
	      set_player_start.c parser_utils.c map_utils.c draw_stripe.c \
	      map_reader.c map_bounds.c map_validate.c cleanup.c \
	      stripe_math.c map_reader_utils.c map_checker.c \
	      create_trgb.c

SRC         = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ         = $(SRC:.c=.o)

all: $(MLX_LIB) $(LIBFT_LIB) $(NAME)

$(MLX_LIB):
	@$(MAKE) -C $(MLX_DIR)

$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_FLAGS) $(MLX_FLAGS) $(INCLUDES) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
