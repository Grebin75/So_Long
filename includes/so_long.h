/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:57:42 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/09/22 15:49:50 by hcoutinh         ###   ########.fr       */
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
	int			wcount;
	int			pcount;
	int			ccount;
	int			ecount;
	int			xcount;
	int			sizey;
	int			sizex;
	int			steps;
	char		**map;
	void		*win;
	t_player	player;
	t_list		*enemys;
}	t_map;


typedef struct s_menu{
	void		*win;
	void		**img;
	int			op;
	int			wimg;
	int			himg;
}	t_menu;

typedef struct s_win{
	void		*mlx;
	void		**img;
	char		*str;
	int			wimg;
	int			himg;
	int			valid;
	t_map		map[3];
	t_menu		menu;
}	t_win;


// EXIT AND FREE FUNCTIONS

void	errormsg(int status);
void	freeimgs(void **img);
void	freemap(char **map);
void	closewin(void *mlx ,void *win);
void	exitprog(int status);

// MAP CHECKER FUNCTIONS

char	**file_to_str(int fd, char **map, int count, int mapnum);
void	set_map_values(t_map map, int mapnum);
void	initmaps(char *file, int mapnum);
char	**copymap(char **str, t_map map);
void	checkchars(char c, int i, int x, int y);
void	checkformat(char **str, t_map map);
int		checkcase(char **map, int y, int x);
void	algo(char **map, int y, int x);
void	checkpath(char **str, t_map map);
int		lastcheck(char **map);

t_win	*callwin(void);

// STRING FUNCTIONS
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(char *s);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strdup(char	*s1);
char	*swapchar(char *s, int i);

// MENU FUNCTIONS

void	menu(t_win *win);
int		loop(t_win *win);
void	initimg(t_menu *menu);
void	printback(t_win *win);
int		key(int key, t_menu *menu);
void	swapmenu(int option, t_menu *menu, int key);
void	freemenu(t_menu *menu, int status);


void	creategame(t_win *win);

int		keyhandler(int keycode, t_win *win);

#endif
