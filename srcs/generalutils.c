/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generalutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:30:52 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/10/19 16:28:55 by hcoutinh         ###   ########.fr       */
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
	int		i;

	i = -1;
	while (s1 && s1[++i])
		;
	s2 = (char *)malloc(i + 1);
	if (!s2)
		return (0);
	ft_memmove(s2, s1, i + 1);
	return (s2);
}

char	*swapchar(char *s, int i)
{
	if (i > 9)
	{
		s[7] = '0' + (i / 10);
		s[8] = '0' + (i % 10);
		return (s);
	}
	s[8] = '0' + i;
	return (s);
}
