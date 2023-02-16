/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:21:57 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/16 17:05:00 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_pre_sorting(t_stack *stack, t_move *move)
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
}