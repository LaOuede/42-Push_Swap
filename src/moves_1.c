/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:00:19 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/27 08:53:06 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*These functions do basic moves but update the cost at the same time.*/
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
