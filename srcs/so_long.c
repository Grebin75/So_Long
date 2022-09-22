/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:35:12 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/09/22 15:50:25 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_win	*callwin(void)
{
	static t_win	win;

	return (&win);
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
		return (ft_printf(\
		"\033[1;34mError.\nTry ./so.long [mapname.ber]\n\033[0m"));
	initmaps("map1.ber", 0);
	initmaps("map2.ber", 1);
	initmaps(argv[1], 2);

	callwin()->mlx = mlx_init();
	initmenu(callwin());
	//creategame(callwin());
	mlx_loop(callwin()->mlx);
}
