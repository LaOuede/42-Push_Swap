/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:17:25 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/15 13:14:29 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_minor_algo(t_stack **stack_a, t_move *move)
{
	if ((*stack_a)->index == 3)
		ft_rotate(stack_a, move->rotate_a);
	if ((*stack_a)->next->index == 3)
		ft_reverse(stack_a, move->reverse_a);
	if ((*stack_a)->next->next->index == 3 && (*stack_a)->index != 1)
		ft_swap(stack_a, move->swap_a);
}

int	ft_check_sorted(t_stack *stack_a)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->next->number < stack_a->number)
			return (F);
		stack_a = stack_a->next;
	}
	printf("\n>>>>> Already sorted!😎 <<<<<\n\n");
	return (T);
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_move	*move;

	(void)stack_b;
	move = ft_write_moves();
	if (((*stack_a)->size_total == 2) && (ft_check_sorted(*stack_a) == F))
		ft_swap(stack_a, move->swap_a);
	else if (((*stack_a)->size_total == 3) && (ft_check_sorted(*stack_a) == F))
		ft_minor_algo(stack_a, move);
	free(move);
}
