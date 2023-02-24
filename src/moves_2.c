/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:10:00 by gwenolalero       #+#    #+#             */
/*   Updated: 2023/02/24 10:17:18 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ra_rrb(t_stack *stack, t_move *move)
{
	ft_rotate(&stack->a, move->rotate_a);
	ft_reverse(&stack->b, move->reverse_b);
	stack->actions_a--;
	stack->actions_b++;
}

void	ft_rra_rb(t_stack *stack, t_move *move)
{
	ft_reverse(&stack->a, move->reverse_a);
	ft_rotate(&stack->b, move->rotate_b);
	stack->actions_a++;
	stack->actions_b--;
}
