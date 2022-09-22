/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:35:38 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/09/22 13:22:08 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

// CREATE A NEW OBJ
t_list	*createobj(int x, int y)
{
	t_list	*obj;

	obj = malloc(sizeof(t_list));
	if (!obj)
		return (NULL);
	obj->x = x;
	obj->y = y;
	obj->next = NULL;
	return (obj);
}

// ADD THE NEW OBJ TO THE END
t_list	*addtolist(t_list **list, t_list *new)
{
	t_list	*last;

	if (list)
	{
		last = *list;
		if (*list)
		{
			while (last->next)
				last = last->next;
			last->next = new;
		}
		else
			*list = new;
	}
	return (last);
}

// RETURN THE OBJ ON N POSITION
t_list	*selectobj(t_list *list, int n)
{
	int	i;

	i = -1;
	if (n < 0)
		return (NULL);
	while (++i < n)
		list = list->next;
	return (list);
}

// FREE A SPECIFIC OBJ
void	freeobj(t_list **list, int n)
{
	t_list	*temp;

	temp = selectobj(*list, n);
	if (n > 0)
		(selectobj(*list, n - 1))->next = selectobj(*list, n + 1);
	if (n == 0)
		(*list) = (*list)->next;
	if (temp)
		free(temp);
}

// FREE THE LIST
void	freelist(t_list **list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = *list;
		*list = (*list)->next;
		free(tmp);
	}
}
