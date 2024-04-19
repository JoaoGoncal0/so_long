/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomendes <jomendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:20:46 by jomendes          #+#    #+#             */
/*   Updated: 2024/04/18 20:12:34 by jomendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

# define ESC	65307
# define UP		65362
# define DOWN	65364
# define RIGHT	65363
# define LEFT	65361

typedef struct s_game
{
	char		**map;
	char		**map_ff;
	int			map_width;
	int			map_heigth;
	void		*animation;
	int			player_y;
	int			player_x;
	int			moves;
	int			ncollectible;
	int			ffcollectible;
	void		*mlx;
	void		*win;
	void		**img;
	int			nexit;
	int			nplayer;
	int			ff_exit;

}				t_game;

void			error(t_game *vars, char *str);
int				check_name(char *str, t_game *vars);
int				check_args(int ac, char **av, t_game *vars);
void			init_images(t_game *vars);
void			map_visualizer(t_game *vars);
int				map_heigth(char *file);
char			**get_map(char *file, t_game *vars);
t_game			*start_game(char *file);
void			dance(t_game *vars, int i);
int				animation(t_game *vars);
void			free_game(t_game *vars);
void			game_over(t_game *vars);
void			easy_game(t_game *vars);
int				pressed_x(t_game *vars);
void			moves(int x, int y, t_game *game);
int				check_moves(t_game *vars, int y, int x);
int				key_press(int keycode, t_game *vars);
void			player_position(t_game *vars);
int				quadradinho(char **map);
int				closed_walls_x(t_game *vars);
int				closed_walls_y(t_game *vars);
int				check_map(t_game *vars);
void			count(t_game *vars);
void			flood_fill(t_game *vars, int x, int y);
void			check_char(char **map, t_game *vars);
void			free_map(char **vars);
void			so_long(t_game *vars);
void			free_game1(t_game *vars);
void			init_images1(t_game *vars);
void			map_visualizer1(t_game *vars);
int				map_len(char *str);

#endif
