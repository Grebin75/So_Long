/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:03:17 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/04/14 15:18:01 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			rtn;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	rtn = 1;
	while (1)
	{
		if (buffer[0] == 0)
			rtn = read(fd, buffer, BUFFER_SIZE);
		if (buffer[0])
			line = ft_copy(buffer, line, (len(buffer)) + len(line));
		if (clear(buffer) || rtn <= 0)
			return (line);
	}
}
