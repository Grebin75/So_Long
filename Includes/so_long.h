/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 11:20:34 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/08/25 15:49:01 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../Getnextline/get_next_line.h"
# include "../ft_printf/ft_printf.h"

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

typedef struct t_wall{
	void	*img;
	char	*path;
	int		width;
	int		height;
}	t_wall;

typedef struct t_exit{
	void	*img;
	char	*path;
	int		width;
	int		height;
	int		y;
	int		x;
}	t_exit;

typedef struct t_object{
	void	*img;
	char	*path;
	int		width;
	int		height;
}	t_object;

typedef struct t_grass{
	void	*img;
	char	*path;
	int		width;
	int		height;
}	t_grass;

typedef struct t_map{
	int		wallscount;
	int		playercount;
	int		collectablecount;
	int		exitcount;
	int		enemycount;
	int		size;
	int		sizex;
	char	**map;
}	t_map;

typedef struct t_window{
	void		*win;
	void		*mlx;
	void		*img;
	int			width;
	int			height;
	t_player	player;
	t_grass		grass;
	t_map		map;
	t_wall		wall;
	t_object	object;
	t_exit		exit;
}		t_window;

int			currentpos(int keycode, int y, int x);
int			havecollision(int keycode, int y, int x, char **map);
int			creategrass(int y, int x, t_window *window);
int			createwall(int y, int x, t_window *window);
int			initializeimgs(t_window *window);
int			readtocreate(char **map);
int			counterchecker(t_window *window);
int			lencompare(char **string);
int			ftt_strlen(char *str);
int			illegalchar(t_window *window, char *line);
int			firstandlastwall(char *line);
int			codechecker(char **map);
t_window	*callwindow(void);
int			createplayer(int y, int x, t_window *window);
void		createwin(t_window *window, char **map);
void		closewin(t_window *window);
int			keyhandler(int keycode, t_window *window);
#endif