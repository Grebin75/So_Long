/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maputils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:57:41 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/09/22 15:07:25 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// CHECK INVALID CHARS AND COUNT VALID CHARS
void checkchars(char c, int i, int x, int y)
{
	if (c != '1' && c != 'C' && c != '0' && c != 'E' && c != 'P' && c != 'X')
		exitprog(2);
	if (c == 'P')
	{
		callwin()->map[i].pcount += 1;
		callwin()->map[i].player.x = x;
		callwin()->map[i].player.y = y;
	}
	if (c == 'X')
		if (!addtolist(callwin()->map[i].enemys, createobj(x, y)))
			return (3);
	if (c == 'E')
		callwin()->map[i].ecount += 1;
	if (c == 'C')
		callwin()->map[i].ccount += 1;
}

// CHECK MAP LENGTH, CHECK MAP WALLS, CHECK CHAR COUNTS
void	checkformat(char **str, t_map map)
{

	int x;
	int y;
	y = -1;
	while (str[++y])
	{
		x = -1;
		if (ft_strlen(str[y]) != map.sizex)
			exitprog(4);
		while (str[y][++x])
		{
			if ((y == 0 || y == map.sizey - 1) || (x == 0 || \
			x == map.sizex - 1) && (str[y][x] != '1'))
				return (5);
		}
	}
	if (map.ccount == 0 || map.ecount != 1 || map.pcount != 1)
		return (6);
}

// MOVE OR RETURN
int	checkcase(char **map, int y, int x)
{
	if (map[y][x] != '0' && map[y][x] != 'C')
		return (0);
	map[y][x] = 'P';
	return (1);
}

// REDIRECT TO POSSIBLE MOVE
void	algo(char **map, int y, int x)
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

// CREATE A COPY AND CHECK THE PATH ON THAT COPY
void	checkpath(char **str, t_map map)
{
	char	**temp;
	int		error;
	int		i;

	error = 0;
	temp = copymap(str, map);
	algo(temp, map.player.y, map.player.x);
	error = lastcheck(temp);
	if (temp)
	{
		i = -1;
		while (temp[++i])
			free(temp[i]);
		free(temp);
	}
	if (error)
		exitprog(7);
}
