/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:41:49 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/13 20:20:11 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instructions.h"

static void	print_push(int print)
{
	if (print == PRINT_A)
		ft_printf("pa\n");
	else if (print == PRINT_B)
		ft_printf("pb\n");
}

void	push_list(t_list **from_list, t_list **to_list, int print)
{
	t_list	*current;
	t_list	*next;

	print_push(print);
	current = *from_list;
	next = current->next;
	ft_lstadd_front(to_list, ft_lstnew(current->number, current->index));
	ft_lstdelone(*from_list);
	*from_list = next;
}
