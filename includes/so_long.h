/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:57:42 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/10/19 15:43:06 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "./get_next_line.h"
# include "../printf/ft_printf.h"
# include "./list.h"

# define W 		119
# define A 		97
# define S 		115
# define D 		100

# define ESC	65307

# define LEFT	65361
# define RIGHT	65363
# define UP		65362
# define DOWN	65364
# define ENTER	65293

typedef struct s_player{
	int	x;
	int	y;
}	t_player;

typedef struct s_map{
	int			pcount;
	int			ccount;
	int			ecount;
	int			xcount;
	int			sizey;
	int			sizex;
	int			steps;
	char		**map;
	t_player	player;
}	t_map;

typedef struct s_win{
	void		*mlx;
	void		*win;
	void		**img;
	char		*str;
	int			wimg;
	int			himg;
	int			time;
	int			sprite;
	int			prevsprite;
	t_map		map;
}	t_win;

// EXIT AND FREE FUNCTIONS

void	exitprog(int status);
void	printerror(int error, char *s);

// MAP CHECKER FUNCTIONS

void	checkmap(char *file);
char	**file_to_str(int fd, char **map, int count);
void	set_map_values(t_map *map);
char	**copymap(char **str, t_map map);
void	checkformat(t_map *map);
void	checkpath(char **str, t_map map);
void	lastcheck(char **map);

t_win	*this(void);
int		animation(t_win *win);
int		crossclose(t_win *win);
int		keyhandler(int key, t_win *win);

// STRING FUNCTIONS
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strdup(char	*s1);
char	*swapchar(char *s, int i);

void	creategame(t_win *win);

#endif
