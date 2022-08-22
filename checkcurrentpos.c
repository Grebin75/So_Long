/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkcurrentpos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:53:27 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/08/22 14:31:03 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/so_long.h"

int currentpos(int move, int direction, int y, int x)
{
	char **map;
	
	map = callwindow()->map.map;
	if (direction == RIGHT || direction == LEFT)
	{
		if (map[y][x + move] == 'C')
			callwindow()->map.collectablecount -= 1;
		if (map[y][x + move] == '1' || (map[y][x + move] == 'E' && callwindow()->map.collectablecount != 0))
			return (0);
		else if (callwindow()->map.collectablecount == 0 && (map[y][x + move] == 'E' || map[y][x + move] == 'E'))
			closewin(callwindow());
		else
			{
				mlx_put_image_to_window(callwindow()->mlx, callwindow()->win, callwindow()->grass.img, (x * 64), (y * 64));
				callwindow()->player.x += move;
				mlx_put_image_to_window(callwindow()->mlx, callwindow()->win, callwindow()->player.img, (callwindow()->player.x * 64), (y * 64));
			}		
	}
	if (direction == UP || direction == DOWN)
	{
		if (map[y + move][x] == 'C')
			callwindow()->map.collectablecount -= 1;
		if (map[y + move][x] == '1'|| (map[y + move][x] == 'E' && callwindow()->map.collectablecount != 0))
			return (0);
		else if (callwindow()->map.collectablecount == 0 && (map[y + move][x] == 'E' || map[y][x + move] == 'E'))
			closewin(callwindow());
		else
			{
				mlx_put_image_to_window(callwindow()->mlx, callwindow()->win, callwindow()->grass.img, (x * 64), (y * 64));
				callwindow()->player.y += move;
				mlx_put_image_to_window(callwindow()->mlx, callwindow()->win, callwindow()->player.img, (callwindow()->player.x * 64), (callwindow()->player.y * 64));
			}
	}
		
	return (0);
}


