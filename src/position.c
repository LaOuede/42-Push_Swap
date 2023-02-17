/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:19:10 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/17 13:03:02 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_find_goal_pos(t_stack *stack)
{
	t_lst	*lst_a;
	t_lst	*lst_b;
	int		goal_pos;
	int		goal_index;

	lst_a = stack->a;
	lst_b = stack->b;
	goal_index = ft_find_index_max(stack->a);
	while (lst_b)
	{
		while (lst_a)
		{
			if ((lst_a->index > lst_b->index && lst_a->index < goal_index)
				|| (lst_a->index < lst_b->index))
			{
				goal_index = lst_a->index;
				goal_pos = lst_a->pos;
			}
			lst_a = lst_a->next;
		}
			lst_b->goal_pos = goal_pos;
			lst_b = lst_b->next;
	}
}

void	ft_get_pos(t_lst *lst)
{
	int		i;
	t_lst	*ptr;

	i = 0;
	ptr = lst;
	while (ptr)
	{
		ptr->pos = i;
		ptr = ptr->next;
		i++;
	}
}

void	ft_position(t_stack *stack)
{
	t_lst	*ptr;

	ptr = stack->b;
	ft_get_pos(stack->a);
	ft_get_pos(stack->b);
	ft_find_goal_pos(stack);
}
