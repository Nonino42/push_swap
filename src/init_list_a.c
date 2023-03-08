/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 09:29:38 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/08 09:54:06 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	check_int(char *nbr)
{
	if (!(ft_isnum(nbr)) ||
		!(ft_atol(nbr) >= -2147483648 && ft_atol(nbr) <= 2147483647))
		return (FALSE);
	return (TRUE);
}

static void	set_list(t_data *data, char **int_str)
{
	int	i;

	i = 0;
	while (int_str && int_str[i])
	{
		if (check_int(int_str[i]) == FALSE)
		{
			ft_freemap(int_str, i);
			ft_lstclear(&data->a);
			// system("leaks push_swap");
			ft_error(ERR_INT);
		}
		if (data->a == NULL)
			data->a = ft_lstnew(ft_atoi(int_str[i]), 0);
		else
			ft_lstadd_back(&data->a, ft_lstnew(ft_atoi(int_str[i]), 0));
		free(int_str[i]);
		i++;
	}
}

static void	find_duplicate(t_list *list_a, int number)
{
	t_list	*current_list;
	int		check;

	current_list = list_a;
	check = 0;
	while (current_list)
	{
		if (current_list->number == number && !check)
			check = 1;
		else if (current_list->number == number && check)
		{
			ft_lstclear(&list_a);
			// system("leaks push_swap");
			ft_error(ERR_DUP);
		}
		current_list = current_list->next;
	}
}

static void	check_duplicate(t_list *list_a)
{
	t_list	*current_list;
	int		number;

	current_list = list_a;
	number = 0;
	while (current_list != NULL)
	{
		number = current_list->number;
		find_duplicate(list_a, number);
		current_list = current_list->next;
	}
}

void	init_list_a(t_data *data, char **integers)
{
	char	**int_str;
	int		i;

	i = 1;
	while (integers[i])
	{
		int_str = ft_split(integers[i], ' ');
		set_list(data, int_str);
		free(int_str);
		i++;
	}
	check_duplicate(data->a);
	set_index(ft_lstsize(data->a), data->a);
}
