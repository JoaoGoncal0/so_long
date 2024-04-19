/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomendes <jomendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:22:18 by jomendes          #+#    #+#             */
/*   Updated: 2024/04/18 20:24:47 by jomendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_name(char *str, t_game *vars)
{
	int	fd;
	int	len;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		error(vars, "File doesn't exist\n");
	len = 0;
	while (str[len] && str[len] != '.')
		len++;
	if (str[len] != '.' || str[len + 1] != 'b' \
	|| str[len + 2] != 'e' || str[len + 3] != 'r' \
	|| str[len + 4] != '\0')
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

int	check_args(int ac, char **av, t_game *vars)
{
	if (ac == 1)
		error(vars, "Choose one map\n");
	if (ac == 2 && !check_name(av[1], vars))
		return (1);
	if (ac > 2)
		error(vars, "Choose only one map\n");
	return (0);
}

int	quadradinho(char **map)
{
	int	i;
	int	row;

	row = map_len(map[0]);
	i = 0;
	while (map[i])
	{
		if (map_len(map[i]) != row)
			return (1);
		i++;
	}
	return (0);
}

int	closed_walls_x(t_game *vars)
{
	int	x;

	x = 0;
	while (x < vars->map_width)
	{
		if (vars->map[0][x] != '1')
			return (1);
		x++;
	}
	x = 0;
	while (x < vars->map_width)
	{
		if (vars->map[vars->map_heigth - 1][x] != '1')
			return (1);
		x++;
	}
	return (0);
}

int	closed_walls_y(t_game *vars)
{
	int	y;

	y = 0;
	while (y < vars->map_heigth)
	{
		if (vars->map[y][0] != '1')
			return (1);
		y++;
	}
	y = 0;
	while (y < vars->map_heigth)
	{
		if (vars->map[y][vars->map_width - 1] != '1')
			return (1);
		y++;
	}
	return (0);
}
