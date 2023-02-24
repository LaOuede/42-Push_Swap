/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:00:19 by gwenolalero       #+#    #+#             */
/*   Updated: 2023/02/24 15:07:21 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ra(t_stack *stack, t_move *move)
{
	ft_rotate(&stack->a, move->rotate_a);
	stack->actions_a--;
}

void	ft_rb(t_stack *stack, t_move *move)
{
	ft_rotate(&stack->b, move->rotate_b);
	stack->actions_b--;
}

void	ft_rra(t_stack *stack, t_move *move)
{
	ft_reverse(&stack->a, move->reverse_a);
	stack->actions_a++;
}

void	ft_rrb(t_stack *stack, t_move *move)
{
	ft_reverse(&stack->b, move->reverse_b);
	stack->actions_b++;
}
