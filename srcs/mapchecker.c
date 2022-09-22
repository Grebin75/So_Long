/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:42:01 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/09/22 15:05:03 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* void	algo(char **map, int y, int x)
{
	if (checkcase(map, y, x - 1))
		algo(map, y, x - 1);
	if (checkcase(map, y, x + 1))
		algo(map, y, x + 1);
	if (checkcase(map, y - 1, x))
		algo(map, y - 1, x);
	if (checkcase(map, y + 1, x))
		algo(map, y + 1, x);
}

void	checkpath(char **map)
{
	char	**temp;
	int		error;
	int		i;

	error = 0;
	temp = copymap(map);
	algo(temp, callwin()->player.y, callwin()->player.x);
	error = lastcheck(temp);
	if (temp)
	{
		i = -1;
		while (temp[++i])
			free(temp[i]);
		free(temp);
	}
	if (error)
		exitprog(1);
}

void	checkformat(char **map)
{
	int		y;
	int		x;
	t_win	*win;

	y = -1;
	win = callwin();
	win->map.sizex = ft_strlen(map[0]);
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			checker(map, x, y);
		}
	}
	if (win->map.ccount == 0 || win->map.ecount != 1 || win->map.pcount != 1)
		exitprog(1);
}

void	checkmap(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (ft_strncmp(ft_strrchr(file, '.'), ".ber", 5) || fd == -1)
		exitprog(1);
	(callwin()->map.map) = mapcode(fd, NULL, 0);
	checkformat(callwin()->map.map);
	checkpath(callwin()->map.map);
}
 */
