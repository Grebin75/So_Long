/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapinit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:47:35 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/09/22 15:01:29 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// CONVERT FILE .ber TO STRING
char	**file_to_str(int fd, char **map, int count, int mapnum)
{
	char	*temp;

	temp = get_next_line(fd);
	if (temp)
		map = mapcode(fd, map, count + 1);
	else
	{
		map = malloc(sizeof(char *) * (count + 1));
		callwin()->map[mapnum].sizey = count;
	}
	if (!map)
		exitprog(3);
	if (map)
		map[count] = temp;
	return (map);
}

// SET MAP VALUES
void	set_map_values(t_map map, int mapnum)
{
	int x;
	int y;

	y = -1;
	map.sizex = ft_strlen(map.map[0]);
	while (map.map[++y])
	{
		x = -1;
		while (map.map[y][++x])
			checkchars(map.map[y][x], mapnum, x, y);
	}
}

// INITIALIZE VALUES AND HANDLE THE CHECKERS
void initmaps(char *file, int mapnum)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (ft_strncmp(ft_strrchr(file, '.'), ".ber", 5) || fd == -1)
		exitprog(1);
	(callwin()->map[mapnum].map) = file_to_str(fd, NULL, 0, mapnum);
	set_map_values(callwin()->map[mapnum], mapnum);
	checkformat(callwin()->map[mapnum].map, callwin()->map[mapnum]);
	checkpath(callwin()->map[mapnum].map, callwin()->map[mapnum]);
}
