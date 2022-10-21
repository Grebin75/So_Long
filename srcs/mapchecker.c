/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:43:51 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/10/19 16:47:47 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**file_to_str(int fd, char **map, int count)
{
	char	*temp;

	temp = get_next_line(fd);
	if (temp)
		map = file_to_str(fd, map, count + 1);
	else
	{
		map = malloc(sizeof(char *) * (count + 1));
		this()->map.sizey = count;
	}
	if (!map)
		printerror(1, "Error map malloc");
	if (map)
		map[count] = temp;
	return (map);
}

void	checkchars(char c, int x, int y)
{
	if (c != '1' && c != 'C' && c != '0' && c != 'E' && c != 'P' && c != 'X')
		printerror(1, "Invalid chars");
	if (c == 'P')
	{
		this()->map.pcount += 1;
		this()->map.player.x = x;
		this()->map.player.y = y;
	}
	if (c == 'E')
		this()->map.ecount += 1;
	if (c == 'C')
		this()->map.ccount += 1;
}

void	checkformat(t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
		{
			if (((y == 0 || y == map->sizey - 1) || (x == 0 || \
			x == map->sizex - 1)) && (map->map[y][x] != '1'))
				printerror(1, "Map isnt surrounded by walls");
		}
	}
	if (map->ccount == 0 || map->ecount != 1 || map->pcount != 1)
		printerror(1, "Missing or extra chars");
}

void	set_map_values(t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (map->map[0] && map->map[0][++map->sizex])
		;
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
			checkchars(map->map[y][x], x, y);
		if (x != map->sizex)
			printerror(1, "Map isnt rectangular");
	}
}

void	checkmap(char *file)
{
	int	fd;

	if (ft_strncmp(ft_strrchr(file, '.'), ".ber", 5))
		printerror(1, "Invalid file");
	fd = open(file, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		printerror(1, "It's a directory");
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
		printerror(1, "Invalid file");
	(this()->map.map) = file_to_str(fd, NULL, 0);
	if (!(this()->map.map) || !this()->map.map[0])
		printerror(1, "Empty file");
	set_map_values(&this()->map);
	checkformat(&this()->map);
	checkpath(this()->map.map, this()->map);
}
