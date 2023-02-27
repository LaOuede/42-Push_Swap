/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:19:10 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/27 08:49:27 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	search_best_pos(t_stack *stack, t_lst *lst_b, int goal_index)
{
	t_lst	*lst_a;

	lst_a = stack->a;
	while (lst_a)
	{
		if (lst_b->index > lst_a->index && lst_b->index > goal_index
			&& lst_a->index >= goal_index)
		{
			goal_index = lst_a->index;
			lst_b->goal_pos = (lst_a->pos + 1);
		}
		lst_a = lst_a->next;
	}
}

static void	ft_find_goal_pos(t_stack *stack)
{
	t_lst	*lst_a;
	t_lst	*lst_b;
	int		goal_index;

	lst_a = stack->a;
	lst_b = stack->b;
	while (lst_b)
	{
		goal_index = ft_find_index_min(stack->a);
		if (lst_b->index < goal_index)
		{
			while (lst_a->index != goal_index)
				lst_a = lst_a->next;
			lst_b->goal_pos = lst_a->pos;
		}
		else
			search_best_pos(stack, lst_b, goal_index);
		lst_a = stack->a;
		lst_b = lst_b->next;
	}
}

static void	ft_get_pos(t_lst *lst, int size)
{
	int		i;
	int		j;
	int		median;
	t_lst	*ptr;

	i = 0;
	ptr = lst;
	median = size / 2;
	while (i <= median)
	{
		ptr->pos = i++;
		ptr = ptr->next;
	}
	ptr = ft_lst_last(lst);
	i = 0;
	j = 0;
	while (j++ < median)
	{
		ptr->pos = --i;
		ptr = ptr->prev;
	}
}

/*This function gives a position for each element and then finds
the best position for each element (from b) on stack a*/
void	ft_position(t_stack *stack)
{
	ft_get_pos(stack->a, ft_lst_size(&stack->a));
	ft_get_pos(stack->b, ft_lst_size(&stack->b));
	ft_find_goal_pos(stack);
}
