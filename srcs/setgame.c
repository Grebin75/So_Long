/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setgame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:10:55 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/10/19 15:32:39 by hcoutinh         ###   ########.fr       */
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
		printerror(1, "Asset doesnt exist");
	win->img = malloc(sizeof (void *) * (11 + 1));
	if (!win->img)
		printerror(1, "Malloc error");
	while (++i < 11)
	{
		win->img[i] = mlx_xpm_file_to_image(win->mlx, \
		swapchar(path, i + 1), &win->wimg, &win->himg);
		if (!win->img[i])
			printerror(1, "Malloc error");
	}
	win->img[i] = 0;
	free(path);
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
			mlx_put_image_to_window(this()->mlx, this()->win, this()->img[\
			(map[y][x] == 'C') * 9 + (map[y][x] == 'E') * 4 + \
			(map[y][x] == 'P') * 0 + (map[y][x] == '1') * 5 + \
			(map[y][x] == '0') * 7 + (map[y][x] == 'X') * 6], x * 64, y * 64);
		}
	}
	return (0);
}

int	animation(t_win *win)
{
	int	y;
	int	x;

	++win->time;
	y = -1;
	if (win->time == 30000 || win->time == 60000 || win->time == 90000 || \
	win->time == 120000)
	{
		while (win->map.map[++y])
		{
			x = -1;
			while (win->map.map[y][++x])
			{
				if (win->map.map[y][x] == 'C')
					mlx_put_image_to_window(win->mlx, win->win, \
					win->img[win->sprite], x * 64, y * 64);
			}
		}
		win->sprite = 8 * (win->time == 30000) + 9 * (win->time == 60000) + \
		10 * (win->time == 90000) + 9 * (win->time == 120000);
		if (win->time == 120000)
			win->time = 0;
	}
	return (0);
}

void	creategame(t_win *win)
{
	initimgs(win);
	win->map.steps = 0;
	readtocreate(win->map.map);
}
