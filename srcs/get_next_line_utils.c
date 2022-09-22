/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:57:27 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/08/26 11:38:08 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int	len(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == '\n')
			break ;
		i++;
	}
	return (i);
}

char	*ft_copy(char *buffer, char *line, int size)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = line;
	line = malloc(size + 1);
	if (!line)
		return (0);
	while (temp && temp[j])
	{
		line[j] = temp[j];
		j++;
	}
	while (i < len(buffer))
	{
		line[j++] = buffer[i++];
	}
	line[j] = 0;
	if (temp)
		free(temp);
	return (line);
}

int	clear(char *buffer)
{
	int	i;
	int	j;
	int	new;

	i = 0;
	j = 0;
	new = 0;
	while (buffer[i])
	{
		if (new)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n')
			new = 1;
		buffer[i++] = 0;
	}
	return (new);
}
