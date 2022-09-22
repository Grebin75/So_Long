/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generalutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:30:52 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/09/06 14:17:59 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	if (d == NULL && s == NULL)
		return (NULL);
	if (d < s)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		d = d + (n - 1);
		s = s + (n - 1);
		while (n--)
			*d-- = *s--;
	}
	return (dest);
}

char	*ft_strdup(char	*s1)
{
	char	*s2;

	s2 = (char *)malloc(ft_strlen(s1) + 1);
	if (!s2)
		return (0);
	ft_memmove(s2, s1, ft_strlen(s1) + 1);
	return (s2);
}

int	lastcheck(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		if (ft_strrchr(map[i], 'C'))
			return (1);
		if (ft_strrchr(map[i], 'E'))
		{
			j = -1;
			while (map[i][++j] != 'E')
				;
			if (!(map[i][j + 1] == 'P' || map[i][j - 1] == 'P' \
			|| map[i + 1][j] == 'P' || map[i - 1][j] == 'P'))
				return (1);
		}
	}
	return (0);
}

int	checkcase(char **map, int y, int x)
{
	if (map[y][x] != '0' && map[y][x] != 'C')
		return (0);
	map[y][x] = 'P';
	return (1);
}

char	*swapchar(char *s, int i)
{

	s[8] = '0' + i;
	return (s);
}
