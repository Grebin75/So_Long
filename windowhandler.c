/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windowhandler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 11:39:36 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/08/17 17:03:32 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/so_long.h"

void closewin(t_window *window)
{
	//mlx_destroy_image(window->mlx, player->img);
	mlx_destroy_display(window->mlx);
	//mlx_destroy_window(window->mlx, window->win);
	exit (0);
}

void createwin(t_window *window)
{
	window->width = 1080;
	window->height = 1080;
	
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, window->width, window->height, "First LvL");
	creategrass(window);
	createplayer(window);
	mlx_hook(window->win, 02, (1L<<0), keyhandler, window);
	mlx_loop(window->mlx);
	return ;
}

void createplayer(t_window *window)
{
	t_player *player;

	player = &window->player;
	player->x = 0;
	player->y = 0;
	player->path = "./Assets/Characters/player.xpm";	
	player->img = mlx_xpm_file_to_image(window->mlx, player->path, &player->width, &player->height);
	mlx_put_image_to_window(window->mlx, window->win, player->img, player->x, player->y);
	
	
}

int creategrass(t_window *window)
{
	t_grass *grass;
	
	grass = &window->grass;
	grass->x = 0;
	grass->y = 0;
	grass->path = "./Assets/Map/grass.xpm";
	grass->img = mlx_xpm_file_to_image(window->mlx, grass->path, &grass->width, &grass->height);
	while (grass->y < window->height)
	{
		grass->x = 0;
		while (grass->x < window->width)
		{
			mlx_put_image_to_window(window->mlx, window->win, grass->img, grass->x, grass->y);
			grass->x += 64;
		}
		mlx_put_image_to_window(window->mlx, window->win, grass->img, grass->x, grass->y);
		grass->y += 64;
		
	}
	return (0);
}

t_window	*callwindow()
{
	static t_window window;
	
	return(&window);
}

int moveplayer(t_player *player, t_grass *grass, t_window *window, int direction)
{
	mlx_put_image_to_window(window->mlx, window->win, grass->img, player->x, player->y);
	if (direction == RIGHT)
		player->x += 64;
	if (direction == LEFT)
		player->x -= 64;
	if (direction == DOWN)
		player->y += 64;
	if (direction == UP)
		player->y -= 64;
	mlx_put_image_to_window(window->mlx, window->win, player->img, player->x, player->y);
	return (0);
}