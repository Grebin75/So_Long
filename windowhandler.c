/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windowhandler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 11:39:36 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/08/14 16:40:08 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void closewin(t_window *window)
{
	mlx_destroy_window(window->mlx, window->win);
	exit (0);
}

void createwin(t_window *window)
{
	window->width = 1024;
	window->height = 968;
	
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, window->width, window->height, "First LvL");
	mlx_hook(window->win, 02, (1L<<0), keyhandler, window);
	createplayer(window->mlx);
	mlx_loop(window->mlx);
	return ;
}

void createplayer(t_window *window)
{
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;

	relative_path = "./Assets/Character/player.xpm";	
	img = mlx_xpm_file_to_image(window->mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(window->mlx, window->win, img, img_width, img_height);
}
	