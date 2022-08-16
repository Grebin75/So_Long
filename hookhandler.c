/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookhandler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 12:47:31 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/08/16 16:33:44 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int keyhandler(int keycode, t_window *window)
{
	if (keycode == ESC)
		closewin(window);
	if (keycode == D || keycode == RIGHT)
		moveplayer(&window->player, &window->grass, window, RIGHT);
	if (keycode == A || keycode == LEFT)
		moveplayer(&window->player, &window->grass, window, LEFT);
	if (keycode == S || keycode == DOWN)
		moveplayer(&window->player, &window->grass, window, DOWN);
	if (keycode == W || keycode == UP)
		moveplayer(&window->player, &window->grass, window, UP);
	return (0);
}