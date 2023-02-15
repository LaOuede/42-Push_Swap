/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minor_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:38:05 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/15 09:45:04 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_find_index_max(t_stack *stack)
{
	int	max;
	int	size;

	max = 0;
	size = stack->size_total;
	while (stack != NULL)
	{
		if (stack->index == size)
		{
			max = stack->index;
		}
		stack = stack->next;
	}
	return (max);
}

void	ft_minor_algo(t_stack **stack_a, t_move *move)
{
	int		max;

	max = ft_find_index_max(*stack_a);
	if ((*stack_a)->index == max)
		ft_rotate(stack_a, move->rotate_a);
	if ((*stack_a)->next->index == max)
		ft_reverse(stack_a, move->reverse_a);
	if ((*stack_a)->next->next->index == max)
		ft_swap(stack_a, move->swap_a);
}
