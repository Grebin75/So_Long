/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:55:09 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/09/09 12:50:44 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	freemenu(t_menu *menu, int status)
{
	int	i;

	i = -1;
	if (menu->img)
	{
		while (menu->img[++i])
			mlx_destroy_image(callwin()->mlx, menu->img[i]);
		free(menu->img);
	}
	if (menu->win)
		mlx_destroy_window(callwin()->mlx, menu->win);
	if (callwin()->mlx)
		mlx_destroy_display(callwin()->mlx);
	if (status)
		exitprog(0);
}
