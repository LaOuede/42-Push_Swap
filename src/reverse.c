/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:47:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/13 13:47:26 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_reverse(t_stack **stack)
{
	t_stack	*head;
	t_stack	*last;
	t_stack	*penultimate;

	last = ft_stack_last(*stack);
	penultimate = ft_stack_penultimate(*stack);
	head = *stack;
	*stack = last;
	(*stack)->next = head;
	penultimate->next = NULL;
}
