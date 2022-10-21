/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:20:36 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/10/19 16:27:26 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Print error message.
void	printerror(int error, char *s)
{
	if (error)
		ft_printf("Error\n");
	ft_printf("%s\n", s);
	exitprog(error);
}

t_win	*this(void)
{
	static t_win	win;

	return (&win);
}

// Free map, images, window and mlx and exit the program.
void	exitprog(int status)
{
	int	i;

	i = -1;
	if (this()->map.map)
	{
		while (this()->map.map[++i])
			free(this()->map.map[i]);
		free(this()->map.map);
	}
	i = -1;
	if (this()->img)
	{
		while (this()->img[++i])
			mlx_destroy_image(this()->mlx, this()->img[i]);
		free(this()->img);
	}
	if (this()->mlx)
	{
		if (this()->win)
			mlx_destroy_window(this()->mlx, this()->win);
		mlx_destroy_display(this()->mlx);
		free(this()->mlx);
	}
	exit (status);
}

// Distribute the received parameters
int	main(int argc, char **argv)
{
	this()->sprite = 8;
	if (argc != 2)
		printerror(1, "Try again with ./so_long [map.ber].");
	checkmap(argv[1]);
	this()->mlx = mlx_init();
	if (!this()->mlx)
		printerror(1, "Error on mlx init");
	(this()->win) = mlx_new_window(this()->mlx, this()->map.sizex * 64, \
	this()->map.sizey * 64, "so_long");
	if (!this()->win)
		printerror(1, "Error on mlx create window");
	creategame(this());
	mlx_hook(this()->win, 17, (1L << 2), crossclose, this());
	mlx_loop_hook(this()->mlx, animation, this());
	mlx_hook(this()->win, 02, (1L << 0), keyhandler, this());
	mlx_loop(this()->mlx);
	exitprog(0);
}
