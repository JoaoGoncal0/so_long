/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomendes <jomendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:36:36 by jomendes          #+#    #+#             */
/*   Updated: 2024/04/15 17:18:14 by jomendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_game *vars, int x, int y)
{
	if (!vars->map_ff || x < 0 || x >= vars->map_width || \
	y < 0 || y >= vars->map_heigth || vars->map_ff[y][x] == '1' || \
	vars->map_ff[y][x] == 'S')
		return ;
	if (vars->map_ff[y][x] == 'C')
	{
		vars->ffcollectible++;
	}
	if (vars->map_ff[y][x] == 'E')
	{
		vars->ff_exit++;
		vars->map_ff[y][x] = '1';
		return ;
	}
	vars->map_ff[y][x] = '1';
	flood_fill(vars, x - 1, y);
	flood_fill(vars, x + 1, y);
	flood_fill(vars, x, y - 1);
	flood_fill(vars, x, y + 1);
}
