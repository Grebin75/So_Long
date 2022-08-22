/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windowhandler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 11:39:36 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/08/22 12:05:55 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/so_long.h"

void closewin(t_window *window)
{
	int i;

	i = -1;
	while (window->map.map[++i])
		free(window->map.map[i]);
	free(window->map.map);
	mlx_destroy_image(window->mlx, window->object.img);
	mlx_destroy_image(window->mlx, window->wall.img);
	mlx_destroy_image(window->mlx, window->exit.img);
	mlx_destroy_image(window->mlx, window->grass.img);
	mlx_destroy_image(window->mlx, window->player.img);
	mlx_destroy_window(window->mlx, window->win);
	mlx_destroy_display(window->mlx);
	free(window->mlx);
	
	exit (0);
}

void createwin(t_window *window, char **map)
{
	
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, (window->map.sizex * 64), (window->map.size * 64), "First LvL");
	initializeimgs(window);
	readtocreate(map);
	mlx_hook(window->win, 02, (1L<<0), keyhandler, window);
	mlx_loop(window->mlx);
	return ;
}

t_window	*callwindow()
{
	static t_window window;
	
	return(&window);
}

int moveplayer(t_player *player, t_grass *grass, t_window *window, int direction)
{
	mlx_put_image_to_window(window->mlx, window->win, grass->img, (player->x * 64), (player->y * 64));
	if (direction == RIGHT)
		player->x += 64;
	if (direction == LEFT)
		player->x -= 64;
	if (direction == DOWN)
		player->y += 1;
	if (direction == UP)
		player->y -= 1;
	mlx_put_image_to_window(window->mlx, window->win, player->img, (player->x * 64), (player->y * 64));
	return (0);
}