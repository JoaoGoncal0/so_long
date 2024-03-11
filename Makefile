NAME = so_long

LIBFT = libft/libft.a

PRINTF = ft_printf/libftprintf.a

CC = cc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

MLX_DIR = minilibx-linux

MLX = $(MLX_DIR)/libmlx.a 

MLXFLAGS = -lXext -lX11

SRCS = 		so_long.c\
				map.c\
				get_next_line/get_next_line_bonus.c\
				get_next_line/get_next_line_utils_bonus.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	@make -s -C ./libft
	@make bonus -s -C ./libft

$(PRINTF):
	@make -s -C ./ft_printf

$(NAME):	$(OBJS) $(LIBFT) $(PRINTF) $(MLX)
		ar rcs $(NAME) $(OBJS)
		@${CC} ${CFLAGS} ${OBJS} $(LIBFT) $(PRINTF) $(MLX) $(MLXFLAGS) -o $(NAME)
		@echo "$(NAME) created"

clean:
	$(RM) $(OBJS)
	@make clean -s -C ./libft
	@make clean -s -C ./ft_printf

fclean: clean
	$(RM) $(NAME)
	@make fclean -s -C ./libft
	@make fclean -s -C ./ft_printf
	@echo "$(NAME) deleted"

re: fclean all

.PHONY: fclean all



