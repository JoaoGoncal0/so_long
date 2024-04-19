/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomendes <jomendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:37:57 by jomendes          #+#    #+#             */
/*   Updated: 2024/04/18 20:38:28 by jomendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moves(int x, int y, t_game *vars)
{
	static int	steps;
	char		*itoa;
	int			i;

	vars->map[vars->player_y][vars->player_x] = 'P';
	mlx_put_image_to_window(vars->mlx, vars->win, \
	vars->img[9], vars->player_x * 64, vars->player_y * 64);
	vars->player_x = x;
	vars->player_y = y;
	vars->map[y][x] = 'P';
	mlx_put_image_to_window(vars->mlx, vars->win, \
	vars->img[11], vars->player_x * 64, vars->player_y * 64);
	steps++;
	itoa = ft_itoa(steps);
	i = -1;
	while (++i <= 100)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->img[9], (vars->map_width * 64 + 100) + i, 0);
	}
	mlx_string_put(vars->mlx, vars->win, \
	vars->map_width * 64 + 100, 20, 0xFFFF00, itoa);
	free(itoa);
	ft_printf("Steps = %d\n", steps);
}

int	check_moves(t_game *vars, int x, int y)
{
	if (x < 0 || y < 0)
		return (0);
	if (vars->map[y][x] == '1')
		return (0);
	if (vars->map[y][x] == 'C')
	{
		vars->ncollectible--;
		vars->map[y][x] = '0';
	}
	if (vars->map[y][x] == 'E')
	{
		if (vars->ncollectible == 0)
			easy_game(vars);
		return (0);
	}
	if (vars->map[y][x] == 'S')
		game_over(vars);
	return (1);
}

int	key_press(int keycode, t_game *vars)
{
	int	x;
	int	y;

	if (keycode == ESC)
		free_game(vars);
	if (keycode != DOWN && keycode != UP && keycode != LEFT && keycode != RIGHT)
		return (1);
	x = vars->player_x + ((keycode == RIGHT) - (keycode == LEFT));
	y = vars->player_y + ((keycode == DOWN) - (keycode == UP));
	if (check_moves(vars, x, y))
	{
		moves(x, y, vars);
	}
	return (0);
}

void	player_position(t_game *vars)
{
	int	x;
	int	y;

	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == 'P')
			{
				vars->player_y = y;
				vars->player_x = x;
			}
			x++;
		}
		y++;
	}
}

int	map_len(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '\n')
			count++;
		i++;
	}
	return (count);
}
