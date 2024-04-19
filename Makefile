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
				checkers.c\
				errors.c\
				imagens.c\
				map.c\
				handle_events.c\
				moves.c\
				get_next_line/get_next_line_bonus.c\
				get_next_line/get_next_line_utils_bonus.c\
				floodfill.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	@make -s -C ./libft
	@make bonus -s -C ./libft

$(PRINTF):
	@make -s -C ./ft_printf

$(MLX):
	@make -s -C ./minilibx-linux

$(NAME):	$(OBJS) $(LIBFT) $(PRINTF) $(MLX)
		@${CC} ${CFLAGS} $(MLXFLAGS) ${OBJS} $(LIBFT) $(PRINTF) $(MLX) -o $(NAME)
		@echo "$(NAME) created"

clean:
	$(RM) $(OBJS)
	@make clean -s -C ./libft
	@make clean -s -C ./ft_printf
	@make clean -s -C ./minilibx-linux	


fclean:			clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)
					@$(RM) $(PRINTF)
					@$(RM) $(MLX)
					@echo "$(NAME) deleted"

re: fclean all

.PHONY: fclean all



