/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imagens.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomendes <jomendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:23:10 by jomendes          #+#    #+#             */
/*   Updated: 2024/04/19 10:12:06 by jomendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_images(t_game *vars)
{
	int	i;

	i = 0;
	vars->img = ft_calloc(14, sizeof(void *));
	if (!vars->img)
		return ;
	vars->img[0] = mlx_xpm_file_to_image(vars->mlx, \
		"imagens/Girl1.xpm", &i, &i);
	vars->img[1] = mlx_xpm_file_to_image(vars->mlx, \
		"imagens/Girl2.xpm", &i, &i);
	vars->img[2] = mlx_xpm_file_to_image(vars->mlx, \
		"imagens/Girl3.xpm", &i, &i);
	vars->img[3] = mlx_xpm_file_to_image(vars->mlx, \
		"imagens/Girl4.xpm", &i, &i);
	vars->img[4] = mlx_xpm_file_to_image(vars->mlx, \
		"imagens/Girl5.xpm", &i, &i);
	vars->img[5] = mlx_xpm_file_to_image(vars->mlx, \
		"imagens/Girl6.xpm", &i, &i);
	vars->img[6] = mlx_xpm_file_to_image(vars->mlx, \
		"imagens/Girl7.xpm", &i, &i);
	vars->img[7] = mlx_xpm_file_to_image(vars->mlx, \
		"imagens/Girl8.xpm", &i, &i);
	vars->img[8] = mlx_xpm_file_to_image(vars->mlx, \
		"imagens/Girl9.xpm", &i, &i);
	init_images1(vars);
}

void	init_images1(t_game *vars)
{
	int	i;

	i = 0;
	vars->img[9] = mlx_xpm_file_to_image(vars->mlx, \
		"imagens/DanceFloor.xpm", &i, &i);
	vars->img[10] = mlx_xpm_file_to_image(vars->mlx, \
		"imagens/Beer.xpm", &i, &i);
	vars->img[11] = mlx_xpm_file_to_image(vars->mlx, \
		"imagens/Men.xpm", &i, &i);
	vars->img[12] = mlx_xpm_file_to_image(vars->mlx, \
		"imagens/Security.xpm", &i, &i);
	vars->img[13] = mlx_xpm_file_to_image(vars->mlx, \
		"imagens/Door.xpm", &i, &i);
}

void	map_visualizer1(t_game *vars)
{
	int	y;
	int	x;

	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, \
				vars->img[13], x * 64, y * 64);
			else if (vars->map[y][x] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, \
				vars->img[0], x * 64, y * 64);
			else if (vars->map[y][x] == 'S')
				mlx_put_image_to_window(vars->mlx, vars->win, \
				vars->img[12], x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	map_visualizer(t_game *vars)
{
	int	y;
	int	x;

	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, \
				vars->img[9], x * 64, y * 64);
			else if (vars->map[y][x] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, \
				vars->img[11], x * 64, y * 64);
			else if (vars->map[y][x] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, \
				vars->img[10], x * 64, y * 64);
			map_visualizer1(vars);
			x++;
		}
		y++;
	}
}
