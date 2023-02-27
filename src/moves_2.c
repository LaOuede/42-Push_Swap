/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:10:00 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/27 08:53:18 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*These functions do basic moves but update the cost at the same time.*/
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
