/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:17:25 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/15 09:18:42 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
