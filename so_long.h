/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 11:20:34 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/08/14 16:16:32 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx_linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct t_window{
	void	*win;
	void	*mlx;
	void	*img;
	int		width;
	int		height;
}		t_window;

void createplayer(t_window *window);
void createwin(t_window *window);
void closewin(t_window *window);
int  keyhandler(int keycode, t_window *window);
#endif