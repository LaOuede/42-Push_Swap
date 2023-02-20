/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:19:10 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/20 14:51:34 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_find_goal_pos(t_stack *stack)
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
			lst_b->goal_pos = lst_a->pos;
		while (lst_a)
		{
			if (lst_b->index > lst_a->index && lst_b->index > goal_index)
			{
				goal_index = lst_a->index;
				lst_b->goal_pos = lst_a->next->pos;
			}
			lst_a = lst_a->next;
		}
		lst_a = stack->a;
		lst_b = lst_b->next;
	}
}

void	ft_get_pos(t_lst *lst, int	size)
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
		ptr->pos = i;
		ptr = ptr->next;
		i++;
	}
	ptr = ft_lst_last(lst);
	j = 0;
	i = 0;
	while (j++ < median)
	{
		ptr->pos = --i;
		ptr = ptr->prev;
	}
}

void	ft_position(t_stack *stack)
{
	ft_get_pos(stack->a, ft_lst_size(&stack->a));
	ft_get_pos(stack->b, ft_lst_size(&stack->b));
	ft_find_goal_pos(stack);
}
