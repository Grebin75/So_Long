/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maputils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:43:53 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/10/19 14:35:01 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
		i--;
	}
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = -1;
	if (!s1)
		exitprog(1);
	while (++i < (n - 1) && s1[i] == s2[i] && s1[i] != '\0')
		;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	**copymap(char **str, t_map map)
{
	int		i;
	char	**temp;

	i = -1;
	temp = malloc(sizeof(char *) * (map.sizey + 1));
	if (!temp)
		exitprog(1);
	while (str[++i])
	{
		temp[i] = ft_strdup(str[i]);
		if (!temp[i])
			exitprog(1);
	}
	temp[i] = NULL;
	return (temp);
}
