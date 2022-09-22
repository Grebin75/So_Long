/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windowhandler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:01:26 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/09/22 12:28:07 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	initimgs(t_win *win)
{
	int		i;
	char	*path;

	i = -1;
	win->wimg = 32;
	win->himg = 32;
	path = ft_strdup("assets/01.xpm");
	if (!path)
		exitprog(1);
	win->img = malloc(sizeof (void *) * (9 + 1));
	if (!win->img)
		exitprog(1);
	while (++i < 9)
	{
		win->img[i] = mlx_xpm_file_to_image(win->mlx, \
		swapchar(path, i + 1), &win->wimg, &win->himg);
		if (!win->img[i])
			exitprog(1);
	}
	win->img[i] = 0;
	free(path);
}

int	printimg(int n, int y, int x, t_win *win)
{
	mlx_put_image_to_window(win->mlx, win->win, win->img[n], x * 64, y * 64);
	return (0);
}

int	readtocreate(char **map)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'C')
				printimg(5, y, x, callwin());
			if (map[y][x] == 'E')
				printimg(4, y, x, callwin());
			if (map[y][x] == 'P')
				printimg(0, y, x, callwin());
			if (map[y][x] == '1')
				printimg(8, y, x, callwin());
			if (map[y][x] == '0')
				printimg(7, y, x, callwin());
			if (map[y][x] == 'X')
				printimg(6, y, x, callwin());
		}
	}
	return (0);
}

int	crossclose(t_win *win)
{
	(void)win;
	exitprog(0);
	return (0);
}

void	creategame(t_win *win)
{
	win->mlx = mlx_init();
	initimgs(win);
	win->map.steps = 0;
	win->win = mlx_new_window(win->mlx, win->map.sizex * 64, \
	win->map.sizey * 64, "So_Long");
	readtocreate(win->map.map);
	mlx_hook(win->win, 17, (1L << 2), crossclose, win);
	mlx_hook(win->win, 02, (1L << 0), keyhandler, win);
	mlx_loop(win->mlx);
}
