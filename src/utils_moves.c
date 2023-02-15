/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:21:23 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/15 08:20:13 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_move	*ft_write_moves(void)
{
	t_move	*moves;

	moves = ft_calloc(sizeof * moves, 1);
	if (!moves)
		return (NULL);
	moves->push = "ss";
	moves->push_a = "pa";
	moves->push_b = "pb";
	moves->swap_a = "sa";
	moves->swap_b = "sb";
	moves->rotate = "rr";
	moves->rotate_a = "ra";
	moves->rotate_b = "rb";
	moves->reverse = "rrr";
	moves->reverse_a = "rra";
	moves->reverse_b = "rrb";
	moves->next = NULL;
	return (moves);
}

t_stack	*ft_stack_last(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*ft_stack_penultimate(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}
