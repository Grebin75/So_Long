/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 11:26:46 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/08/25 15:50:18 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/so_long.h"

int	illegalchar(t_window *window, char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == 'P')
			window->map.playercount += 1;
		if (line[i] == 'C')
			window->map.collectablecount += 1;
		if (line[i] == 'E')
			window->map.exitcount += 1;
		if (line[i] != '1' && line[i] != '0' && line[i] != 'E' \
		&& line[i] != 'C' && line[i] != 'P')
			return (0);
		i++;
	}
	return (1);
}

int	firstandlastwall(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	lencompare(char **string)
{
	int	i;

	i = 0;
	while (i < callwindow()->map.size - 1)
	{
		if (ftt_strlen(string[i]) != ftt_strlen(string[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int	counterchecker(t_window *window)
{
	if (window->map.collectablecount == 0)
		return (0);
	if (window->map.playercount != 1)
		return (0);
	if (window->map.exitcount != 1)
		return (0);
	return (1);
}

int	checkpath(char **map)
{
	char	**temp;

	temp = malloc((sizeof(char *) * ftt_strlen(callwindow()->map.map[0])));
	
	
}