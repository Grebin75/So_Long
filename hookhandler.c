/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookhandler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 12:47:31 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/08/25 15:39:57 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/so_long.h"

int	currentpos(int keycode, int y, int x)
{
	t_window	*window;

	window = callwindow();
	if (havecollision(keycode, y, x, window->map.map))
	{
		mlx_put_image_to_window(window->mlx, window->win, window->grass.img, \
		(x * 64), (y * 64));
		mlx_put_image_to_window(window->mlx, window->win, window->player.img, \
		(window->player.x * 64), (window->player.y * 64));
	}
	return (0);
}

int	havecollision(int key, int y, int x, char **map)
{
	x = x + (key == D || key == RIGHT) - (key == A || key == LEFT);
	y = y + (key == S || key == DOWN) - (key == W || key == UP);
	if (map[y][x] == 'C')
	{
		callwindow()->map.collectablecount -= 1;
		map[y][x] = '0';
	}
	if (map[y][x] != '1' && (callwindow()->map.collectablecount == 0 \
	|| map[y][x] != 'E'))
	{
		if (callwindow()->map.collectablecount == 0 && map[y][x] == 'E')
		{
			ft_printf("\033[1;34mMission Complete.\n\033[0m");
			closewin(callwindow());
		}
		callwindow()->player.x = x;
		callwindow()->player.y = y;
		return (1);
	}
	return (0);
}

int	keyhandler(int keycode, t_window *window)
{
	if (keycode == ESC)
		closewin(window);
	if (keycode == D || keycode == RIGHT || keycode == A || keycode == LEFT || \
	keycode == W || keycode == UP || keycode == S || keycode == DOWN)
		currentpos(keycode, callwindow()->player.y, callwindow()->player.x);
	return (0);
}
