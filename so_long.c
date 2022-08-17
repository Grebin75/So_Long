/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 10:32:59 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/08/17 18:46:59 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/so_long.h"

 char **mapcode(int fd, char **map, int count)
{
	char *temp;
	
	temp = get_next_line(fd);
	printf("temp %s" ,temp);
	if (temp)
		map = mapcode(fd, map, count + 1);
	else 
	{
		map = malloc(sizeof(char *) * (count + 1));
		callwindow()->map.size = count + 1; // ta com um a mais
	}
	if (map)
		map[count] = temp; 
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
	int j;
	char *line;
	int k;
	
	i = 0;
	printf("%d\n", callwindow()->map.size);
	while (map[i])
	{
		line = map[i];
		j = 0;
		k = 0;
		while (k < callwindow()->map.size - 2)
		{
			printf("A1\n");
			if (ft_strlen(map[k]) != ft_strlen(map[k + 1]))
				return (0);
			k++;
		}
		if (i == 0 || i  == callwindow()->map.size) // checka walls na primeira e na ultima linha.
		{
			printf("A1\n");
			while (line[j] && line[j] != '\n')
			{
				if (line[j] != '1')
				{
					return (0);
				}
				j++;
			}
		}
		if (line[0] != '1' || line[ft_strlen(line) - 1] != '1') // checka primeira linha e a ultima 
			return (0);
		while (line[j] && line[j] != '\n')
		{
			if (line[j] != '0' && line[j] != '1' && line[j] != 'C' \
			&& line[j] != 'E' && line[j] != 'P') // checka caracteres ilegais
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
int	codehandler(char *path)
{
	int fd;
	char **map;

	fd = open(path, O_RDONLY);
	map = mapcode(fd, NULL, 0);
	return (codechecker(map));
}

int main(int argc, char **argv)
{
	(void)argv;
	if (argc == 2)
		{
			if (codehandler(argv[1]) == 0)
				return (0);
			createwin(callwindow());
		}
	else
	{
		return (write (1 , "\33[1;31mError\033[0m\n", 18));
	}
}
