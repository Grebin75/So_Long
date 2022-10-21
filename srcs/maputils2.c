/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maputils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:43:53 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/10/19 14:27:31 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

// CHECK IF HAVE COINS AND P NEAR E
void	lastcheck(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		if (ft_strrchr(map[i], 'C'))
			printerror(1, "Invalid path");
		if (ft_strrchr(map[i], 'E'))
		{
			j = -1;
			while (map[i][++j] != 'E')
				;
			if (!(map[i][j + 1] == 'P' || map[i][j - 1] == 'P' \
			|| map[i + 1][j] == 'P' || map[i - 1][j] == 'P'))
				printerror(1, "Invalid path");
		}
	}
}

// CREATE A COPY AND CHECK THE PATH ON THAT COPY
void	checkpath(char **str, t_map map)
{
	char	**temp;
	int		i;

	temp = copymap(str, map);
	algo(temp, map.player.y, map.player.x);
	lastcheck(temp);
	if (temp)
	{
		i = -1;
		while (temp[++i])
			free(temp[i]);
		free(temp);
	}
}
