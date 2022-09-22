/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:02:51 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/09/22 15:49:21 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
void	swapmenu(int option, t_menu *menu, int key)
{
	mlx_put_image_to_window(callwin()->mlx, menu->win, menu->img[(3 + option)], 240,  (option + 1) * 40 + ((option != 0) * option * 177));
	menu->op += ((key == DOWN) - (key == UP));
	mlx_put_image_to_window(callwin()->mlx, menu->win, menu->img[menu->op], 240,  (menu->op + 1) * 40 + ((menu->op != 0) * menu->op * 177));
}

int	key(int key, t_menu *menu)
{
	int option;

	option = menu->op;
	if (key == ESC)
		freemenu(menu, 1);
	if (key == ENTER)
		callwin()->valid = 1;
	if ((key == DOWN && option < 2 ) || (key == UP && option > 0))
		swapmenu(option, menu, key);
	return (0);
}

void	printback(t_win *win)
{
	int y;
	int x;

	y = 0;
	while (y < 708)
	{
		x = 0;
		while (x < 720)
		{
			mlx_put_image_to_window(win->mlx, win->menu.win, win->menu.img[6], x, y);
			x += 240;
		}
		mlx_put_image_to_window(win->mlx, win->menu.win, win->menu.img[6], x, y);
		y += 177;
	}

}

void	initimg(t_menu *menu)
{
	int		i;
	char	*path;

	i = -1;
	menu->wimg = 240;
	menu->himg = 177;
	path = ft_strdup("assets/10.xpm");
	if (!path)
		freemenu(menu, 1);
	menu->img = malloc(sizeof (void *) * (7 + 1));
	if (!menu->img)
		freemenu(menu, 1);
	while (++i < 7)
	{
		menu->img[i] = mlx_xpm_file_to_image(callwin()->mlx, \
		swapchar(path, i), &menu->wimg, &menu->himg);
		if (!menu->img[i])
			freemenu(menu, 1);
	}
	menu->img[i] = NULL;
	free(path);
}

int	loop(t_win *win)
{
	if (callwin()->valid)
	{
		mlx_loop_end(win->mlx);
		freemenu(menu, 0);
	}
	return (0);
}

void menu(t_win *win)
{
	initimg(&win->menu);
	win->menu.win = mlx_new_window(win->mlx, 720, 708, "Menu");
	printback(&win);
	mlx_put_image_to_window(win->mlx, win->menu.win, win->menu.img[0], 240, 40);
	mlx_put_image_to_window(win->mlx, win->menu.win, win->menu.img[4], 240, 257);
	mlx_put_image_to_window(win->mlx, win->menu.win, win->menu.img[5], 240, 474);
	mlx_hook(win->menu.win, 02, (1L << 0), key, &win->menu);
	mlx_loop_hook(win->mlx, loop, &menu);
}
