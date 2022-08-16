/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 10:32:59 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/08/16 18:17:51 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	int valid;
	
	if(argc != 2)
		{
			write(1, "Error\n", 6);
		}
	else
	{
		valid = open(argv[2], O_RDONLY);
		get_next_line();
		createwin(callwindow());
	}
	valid = checkmap();
	createwin(callwindow());
}
