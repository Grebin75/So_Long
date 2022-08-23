/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createimgs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 12:36:26 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/08/23 16:58:18 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/so_long.h"

int	readtocreate(char **map)
{
	int			y;
	int			x;
	char		*mapline;
	t_window	*window;

	window = callwindow();
	y = -1;
	while (map[++y])
	{
		mapline = map[y];
		x = -1;
		while (mapline[++x] && mapline[x] != '\n')
		{
			if (mapline[x] == 'P')
				createplayer(y, x, window);
			if (mapline[x] == '1')
				mlx_put_image_to_window(window->mlx, window->win, window->wall.img, (x * 64), (y * 64));
			if (mapline[x] == '0')
				mlx_put_image_to_window(window->mlx, window->win, window->grass.img, (x * 64), (y * 64));
			if (mapline[x] == 'C')
				mlx_put_image_to_window(window->mlx, window->win, window->object.img, (x * 64), (y * 64));
			if (mapline[x] == 'E')
				mlx_put_image_to_window(window->mlx, window->win, window->exit.img, (x * 64), (y * 64));
		}
	}
	return (0);
}

int	initializeimgs(t_window *window)
{
	window->grass.img = mlx_xpm_file_to_image(window->mlx, \
	"Assets/Map/grass.xpm"\
	, &window->grass.width, &window->grass.height);
	window->player.img = mlx_xpm_file_to_image(window->mlx, \
	"Assets/Characters/mewtwo.xpm"\
	, &window->player.width, &window->player.height);
	window->wall.img = mlx_xpm_file_to_image(window->mlx, "Assets/Map/tree.xpm" \
	, &window->wall.width, &window->wall.height);
	window->exit.img = mlx_xpm_file_to_image(window->mlx, \
	"Assets/Objects/start.xpm" \
	, &window->exit.width, &window->exit.height);
	window->object.img = mlx_xpm_file_to_image(window->mlx, \
	"Assets/Objects/coin.xpm" \
	, &window->object.width, &window->object.height);
	return (0);
}

int	createplayer(int y, int x, t_window *window)
{
	window->player.x = x;
	window->player.y = y;
	mlx_put_image_to_window(window->mlx, window->win, window->player.img, \
	(x * 64), (y * 64));
	return (0);
}
