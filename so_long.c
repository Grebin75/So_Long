/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 10:32:59 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/08/19 18:16:55 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/so_long.h"

 char **mapcode(int fd, char **map, int count)
{
	char *temp;
	
	temp = get_next_line(fd);
	if (temp)
		map = mapcode(fd, map, count + 1);
	else 
	{
		map = malloc(sizeof(char *) * (count + 1));
		callwindow()->map.size = count;
	}
	if (map)
		map[count] = temp; 
	printf("temp: %s", temp);
	return (map);
}

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	return (i);
}
int	codechecker(char **map)
{
	int i;
	char *line;
	
	i = 0;
	while (map[i])
	{
		line = map[i];
		if (lencompare(map) == 0)
			return (0);
		if (i == 0 || i  == callwindow()->map.size - 1)
			if (firstandlastwall(map[i]) == 0)
				return (0);
		if (line[0] != '1' || line[ft_strlen(line) - 1] != '1')
			return (0);
		if (illegalchar(callwindow(), map[i]) == 0)
		return (0);
		i++;
	}
	callwindow()->map.sizex = ft_strlen(map[0]);
	
	return (counterchecker(callwindow()));
}
char	**codehandler(char *path)
{
	int fd;
	t_window *window;

	window = callwindow();
	fd = open(path, O_RDONLY);
	callwindow()->map.map = mapcode(fd, NULL, 0);
	if (codechecker(window->map.map) == 0)
		closewin(callwindow());
	return (window->map.map);
}

int main(int argc, char **argv)
{
	if (argc == 2)
		{
			callwindow()->map.map = codehandler(argv[1]);
			createwin(callwindow(), callwindow()->map.map);
		}
	else
	{
		return (write (1 , "\33[1;31mError\033[0m\n", 18));
	}
}
