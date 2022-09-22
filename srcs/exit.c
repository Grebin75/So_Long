/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:40:56 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/09/22 15:08:08 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// DISPLAY ERROR ON TERMINAL
void	errormsg(int status)
{
	if (status == 1)
		printf("\033[1;34mInvalid file.\n.\n\033[0m");
	if (status == 2)
		printf("\033[1;34mIllegal chars.\n.\n\033[0m");
	if (status == 3)
		printf("\033[1;34mMalloc error.\n.\n\033[0m");
	if (status == 4)
		printf("\033[1;34mMap isnt rectangle.\n.\n\033[0m");
	if (status == 5)
		printf("\033[1;34mMap isnt surrounded by walls.\n.\n\033[0m");
	if (status == 6)
		printf("\033[1;34mMissing or extra chars.\n.\n\033[0m");
	if (status == 7)
		printf("\033[1;34mNo valid path.\n.\n\033[0m");
}

// FREE MAP ARRAYS
void	freemap(char **map)
{
	int	i;

	i = -1;
	if (map)
	{
		while (map[++i])
			free(map[i]);
		free(map);
	}
}

// FREE IMAGE POINTERS
void	freeimgs(void **img)
{
	int	i;

	i = -1;
	if (img)
	{
		while (img[++i])
			mlx_destroy_image(callwin()->mlx, img[i]);
		free(img);
	}

}

// CLOSE WINDOW
void	closewin(void *mlx ,void *win)
{
	if (win)
		mlx_destroy_window(mlx, win);
}

// HANDLER FOR EVERY ERROR/EXIT
void	exitprog(int status)
{
	int	i;

	i = -1;
	errormsg(status);
	while (++i < 3)
		freemap(callwin()->map[i].map);
	if (callwin()->mlx)
	{
		mlx_destroy_display(callwin()->mlx);
		free(callwin()->mlx);
	}
	exit (status);
}
