/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 11:20:34 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/08/17 17:53:03 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../Getnextline/get_next_line.h"

# define W 		119
# define A 		97
# define S 		115
# define D 		100

# define ESC	65307

# define LEFT	65361
# define RIGHT	65363
# define UP		65362
# define DOWN 	65364

typedef struct t_player{
	void	*img;
	char	*path;
	int		width;
	int		height;
	int		x;
	int		y;
}	t_player;

typedef struct t_grass{
	void	*img;
	char	*path;
	int		width;
	int		height;
	int		x;
	int		y;
}	t_grass;

typedef struct t_map{
	int wallscount;	
	int	playercount;
	int	collectablecount;
	int	exitcount;
	int	enemycount;
	int	size;
	int sizex;
	
} t_map;
typedef struct t_window{
	void	*win;
	void	*mlx;
	void	*img;
	int		width;
	int		height;
	t_player player;
	t_grass grass;
	t_map	map;
}		t_window;


t_window	*callwindow();
int creategrass(t_window *window);
void createplayer(t_window *window);
void createwin(t_window *window);
void closewin(t_window *window);
int keyhandler(int keycode, t_window *window);
int moveplayer(t_player *player, t_grass *grass, t_window *window, int direction);
#endif