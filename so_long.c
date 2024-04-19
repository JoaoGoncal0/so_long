/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomendes <jomendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:47:32 by jomendes          #+#    #+#             */
/*   Updated: 2024/04/18 20:35:58 by jomendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*start_game(char *file)
{
	t_game	*vars;

	vars = ft_calloc(1, sizeof(t_game));
	if (!vars)
		return (NULL);
	vars->map = get_map(file, vars);
	if (!vars->map || vars->map[0] == NULL)
	{
		free_game(vars);
		return (NULL);
	}
	vars->map_ff = get_map(file, vars);
	player_position(vars);
	vars->map_heigth = map_heigth(file);
	if (vars->map_heigth < 3)
		free_game(vars);
	vars->map_width = ft_strlen(vars->map[0]) - 1;
	count(vars);
	check_map(vars);
	return (vars);
}

void	so_long(t_game *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->map_width * 64 + 200 \
	, vars->map_heigth * 64, "so_long");
	init_images(vars);
	map_visualizer(vars);
	mlx_hook(vars->win, 17, 0, pressed_x, vars);
	mlx_string_put(vars->mlx, vars->win, \
	vars->map_width * 64 + 50, 20, 0xFFFF00, "Steps: ");
	mlx_key_hook(vars->win, key_press, vars);
	mlx_loop_hook(vars->mlx, animation, vars);
	mlx_loop(vars->mlx);
}

int	main(int ac, char **av)
{
	t_game	*vars;

	vars = NULL;
	if (!check_args(ac, av, vars))
		return (0);
	if (ac == 2)
	{
		vars = start_game(av[1]);
		if (!vars)
			return (1);
		so_long(vars);
		free_map(vars->map);
		free_map(vars->map_ff);
		free_game(vars);
		return (0);
	}
	else
	{
		error(vars, "Invalid arguments\n");
		return (1);
	}
}
