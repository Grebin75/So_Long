/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookhandler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 12:47:31 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/08/22 13:15:23 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/so_long.h"

int keyhandler(int keycode, t_window *window)
{
	if (keycode == ESC)
		closewin(window);
	if (keycode == D || keycode == RIGHT)
		currentpos(1, RIGHT, window->player.y, window->player.x);
	if (keycode == A || keycode == LEFT)
		currentpos(-1, LEFT, window->player.y, window->player.x);
	if (keycode == S || keycode == DOWN)
		currentpos(1, DOWN, window->player.y, window->player.x);
	if (keycode == W || keycode == UP)
		currentpos(-1, UP, window->player.y, window->player.x);
	return (0);
}