/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 08:56:22 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/14 16:28:38 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_stack **stack)
{
	int	swap;

	if ((*stack)->size_total < 2)
		return ;
	swap = (*stack)->number;
	(*stack)->number = (*stack)->next->number;
	(*stack)->next->number = swap;
	swap = (*stack)->index;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->index = swap;
}

void	ft_sa(t_stack **stack_a)
{
	ft_swap(stack_a);
	write(1, "sa\n", 3);
}
