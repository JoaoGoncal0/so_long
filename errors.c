/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomendes <jomendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:27:00 by jomendes          #+#    #+#             */
/*   Updated: 2024/04/10 16:41:37 by jomendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(t_game *vars, char *str)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	free_game(vars);
	exit(1);
}

void	free_map(char **map)
{
	int	i;

	if (map)
	{
		i = 0;
		while (map[i++])
			free(map[i++]);
		free(map);
	}
}

void	free_game1(t_game *vars)
{
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	free(vars);
	exit(0);
}

void	free_arr_str(char **astr)
{
	int	i;

	i = 0;
	if (astr == NULL)
		return ;
	while (astr[i] != NULL)
	{
		free(astr[i]);
		i++;
	}
	free(astr);
}

void	free_game(t_game *vars)
{
	int	i;

	if (vars == NULL)
		return ;
	free_arr_str(vars->map);
	free_arr_str(vars->map_ff);
	i = 0;
	if (vars->img)
	{
		i = 0;
		while (i < 14)
			mlx_destroy_image(vars->mlx, vars->img[i++]);
		free(vars->img);
	}
	free_game1(vars);
}
