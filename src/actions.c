/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:47:22 by gwenolalero       #+#    #+#             */
/*   Updated: 2023/02/25 08:44:34 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_min_actions(t_lst *lst)
{
	int	total;

	if (lst->actions_a >= 0 && lst->actions_b >= 0)
	{
		total = ft_find_min(lst->actions_a, lst->actions_b)
			+ ft_abs_val(lst->actions_a - lst->actions_b);
	}
	else if (lst->actions_a < 0 && lst->actions_b < 0)
	{
		total = ft_find_min(lst->abs_actions_a, lst->abs_actions_b)
			+ ft_abs_val(lst->actions_a - lst->actions_b);
	}
	else
		total = lst->abs_actions_a + lst->abs_actions_b;
	return (total);
}

static void	ft_choose_move(t_stack *stack)
{
	int		total;
	int		actions;
	t_lst	*ptr ;

	ptr = stack->b;
	actions = INT_MAX;
	while (ptr)
	{
		total = ft_min_actions(ptr);
		if (total < actions)
		{
			actions = total;
			stack->actions_a = ptr->actions_a;
			stack->actions_b = ptr->actions_b;
		}
		ptr = ptr->next;
	}
}

void	ft_actions(t_stack *stack)
{
	t_lst	*lst_b;

	lst_b = stack->b;
	while (lst_b)
	{
		lst_b->actions_a = lst_b->goal_pos;
		lst_b->actions_b = lst_b->pos;
		lst_b->abs_actions_a = ft_abs_val(lst_b->actions_a);
		lst_b->abs_actions_b = ft_abs_val(lst_b->actions_b);
		lst_b = lst_b->next;
	}
	ft_choose_move(stack);
}
