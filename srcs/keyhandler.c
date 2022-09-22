/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:16:46 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/09/19 13:42:22 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	poschecker(t_win *win, char **map, int y, int x)
{
	if (map[y][x] == '1' || (map[y][x] == 'E' \
	&& win->map.ccount != 0))
		return (0);
	if ((map[y][x] == 'E' && win->map.ccount == 0))
	{
		ft_printf("\033[1;34mMission Complete.\n\033[0m");
		exitprog(0);
	}
	if ((map[y][x] == 'X'))
	{
		ft_printf("\033[1;34mYou Died.\n\033[0m");
		exitprog(0);
	}
	if ((map[y][x] == 'C'))
	{
		map[y][x] = '0';
		callwin()->map.ccount -= 1;
	}
	return (1);
}

int	checkcurrentpos(char **map, int y, int x, int key)
{
	t_win	*win;
	int		move;

	move = ((key == S) + (2 *(key == A)) + \
	(3 * (key == D) + (4 * (key == W))) - 1);
	win = callwin();
	x += (key == D) + -(key == A);
	y += (key == S) + -(key == W);
	if (!poschecker(win, map, y, x))
		return (0);
	mlx_put_image_to_window(win->mlx, win->win, win->img[7], \
	win->player.x * 64, win->player.y * 64);
	win->player.x = x;
	win->player.y = y;
	win->map.steps += 1;
	return (mlx_put_image_to_window(win->mlx, win->win, win->img[move], \
	(x * 64), (y * 64)));
}

char	*itoa(int n, int *numdig, int count, char *s)
{
	*numdig = count;
	if (n > 9)
		s = itoa(n / 10, numdig, count + 1, s);
	if (!s)
		s = calloc(sizeof(char), (count + 1));
	if (!s)
		return (NULL);
	s[*numdig - count] = n % 10 + 48;
	return (s);
}

int	keyhandler(int key, t_win *win)
{
	char	*str;
	int		i;

	i = 0;
	if (key == ESC)
		exitprog(0);
	if (key == D || key == A || key == S || key == W)
	{
		checkcurrentpos(win->map.map,\
		 win->player.y, win->player.x, key);
		mlx_put_image_to_window(win->mlx, win->win, win->img[8], 0, 0);
		str = itoa(win->map.steps, &i, 1, NULL);
		mlx_string_put(win->mlx, win->win, 10, 10, 0x0000FF, str);
		free(str);
	}
	return (0);
}
