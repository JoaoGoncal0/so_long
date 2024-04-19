/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomendes <jomendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:41:21 by jomendes          #+#    #+#             */
/*   Updated: 2024/04/18 19:30:50 by jomendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_heigth(char *file)
{
	int		fd;
	char	*row;
	int		counter;
	int		i;

	counter = 0;
	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	row = get_next_line(fd);
	while (row)
	{
		if (counter == 0)
			free(row);
		row = get_next_line(fd);
		free(row);
		counter++;
	}
	free(row);
	close(fd);
	return (counter);
}

char	**get_map(char *file, t_game *vars)
{
	int		fd;
	int		lines_number;
	char	**map;
	char	*row;
	int		line;

	fd = open(file, O_RDONLY);
	lines_number = map_heigth(file);
	map = ft_calloc((lines_number + 1), sizeof(char *));
	line = 0;
	if (fd < 3)
	{
		error (vars, "Map not found\n");
		return (NULL);
	}
	while (line < lines_number)
	{
		row = get_next_line(fd);
		map[line++] = row;
	}
	map[line] = NULL;
	close(fd);
	return (map);
}

void	count(t_game *vars)
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
				vars->nplayer++;
			if (vars->map[y][x] == 'C')
				vars->ncollectible++;
			if (vars->map[y][x] == 'E')
				vars->nexit++;
			x++;
		}
		y++;
	}
}

int	check_map(t_game *vars)
{
	if (quadradinho(vars->map))
		error(vars, "Map is not rectangular\n");
	if (closed_walls_x(vars))
		error(vars, "Map is not closed by walls\n");
	if (closed_walls_y(vars))
		error(vars, "Map is not closed by walls\n");
	if (vars->nexit != 1)
		error(vars, "We need 1 exit\n");
	if (vars->nplayer != 1)
		error(vars, "We need 1 player\n");
	if (vars->ncollectible < 1)
		error(vars, "There are no collectibles\n");
	check_char(vars->map, vars);
	flood_fill(vars, vars->player_x, vars->player_y);
	if (vars->ffcollectible != vars->ncollectible)
		error(vars, "Collectibles not reachable\n");
	if (vars->ff_exit != 1)
		error (vars, "Cant get to the exit\n");
	return (0);
}

void	check_char(char **map, t_game *vars)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != 'P' && map[y][x] != '0' && map[y][x] != '1' && \
			map[y][x] != 'E' && map[y][x] != 'S' && map[y][x] != 'C' \
			&& map[y][x] != 10)
			{
				error(vars, "Wrong characteres on the map\n");
				return ;
			}
			x++;
		}
		y++;
	}
}
