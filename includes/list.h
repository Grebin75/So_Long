/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:38:27 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/09/22 13:22:28 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_list	t_list;

struct s_list
{
	int		y;
	int		x;
	t_list	*next;
};

t_list	*createobj(int x, int y);
t_list	*addtolist(t_list **list, t_list *new);
t_list	*selectobj(t_list *list, int n);

void	freeobj(t_list **list, int n);
void	freelist(t_list **list);

#endif
