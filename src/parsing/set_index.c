/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:01:11 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/13 20:22:57 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parsing.h"

static void	put_index_min(t_list *list_a, int min, int index)
{
	t_list	*current_list;

	current_list = list_a;
	while (current_list)
	{
		if (current_list->number == min)
			current_list->index = index;
		current_list = current_list->next;
	}
}

static int	set_min(t_list *list_a)
{
	t_list	*current_list;
	int		min;

	current_list = list_a;
	min = 0;
	while (current_list != NULL)
	{
		if (current_list->index == 0)
		{
			min = current_list->number;
			break ;
		}
		current_list = current_list->next;
	}
	return (min);
}

void	set_index(int length, t_list *list_a)
{
	t_list	*current_list;
	int		min;
	int		index;

	index = 1;
	current_list = list_a;
	while (index <= length)
	{
		min = set_min(list_a);
		current_list = list_a;
		while (current_list)
		{
			if (current_list->number < min && !current_list->index)
				min = current_list->number;
			current_list = current_list->next;
		}
		put_index_min(list_a, min, index);
		index++;
	}
}
