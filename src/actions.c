/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:47:22 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/27 08:50:44 by gle-roux         ###   ########.fr       */
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

/*This function calculates the number of actions needed in order to
move an element from b to a. Then, the function selects the cheapest move
among all elements and does the move.*/
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
