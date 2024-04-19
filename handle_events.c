/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomendes <jomendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:54:15 by jomendes          #+#    #+#             */
/*   Updated: 2024/04/10 12:57:52 by jomendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_over(t_game *vars)
{
	write (1, "Security kicked you out\n", 24);
	free_game(vars);
}

void	easy_game(t_game *vars)
{
	write (1, "Good luck with the hangover\n", 28);
	free_game(vars);
}

int	pressed_x(t_game *vars)
{
	key_press(ESC, vars);
	return (0);
}

void	dance(t_game *vars, int i)
{
	int	x;
	int	y;

	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == '1')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, \
				vars->img[i], x * 64, y * 64);
			}
			x++;
		}
		y++;
	}
}

int	animation(t_game *vars)
{
	static int	i;
	static int	next_image;

	if (i == 15000)
	{
		vars->animation = vars->img[next_image];
		dance(vars, next_image);
		next_image++;
		if (next_image > 8)
			next_image = 0;
		i = 0;
	}
	else
		i++;
	return (0);
}
