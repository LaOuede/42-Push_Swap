/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 08:37:39 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/17 16:00:06 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* void	ft_move_cost(t_lst *lst)
{
	
} */

void	ft_bring_b_back(t_stack *stack, t_move *move)
{
	(void) move;
	ft_position(stack);
//	ft_move_cost(stack->b);
}

void	ft_pre_sorting_big(t_stack *stack, t_move *move)
{
	int	push;
	int	median;

	push = 0;
	median = (stack->size_total / 2);
	while (push < median)
	{
		if (stack->a->index <= median)
		{
			ft_push(&stack->a, &stack->b, move->push_b);
				push++;
		}
		else
			ft_rotate(&stack->a, move->rotate_a);
	}
	if (ft_lst_size(&stack->a) > 3)
	{
		while (ft_lst_size(&stack->a) > 3)
		{
			if (stack->a->index < (stack->size_total - 2))
				ft_push(&stack->a, &stack->b, move->push_b);
			else
				ft_rotate(&stack->a, move->rotate_a);
		}
	}
}

void	ft_big_algo(t_stack *stack, t_move *move)
{
	ft_pre_sorting_big(stack, move);
	ft_three_algo(stack, &stack->a, move);
	ft_bring_b_back(stack, move);
}
