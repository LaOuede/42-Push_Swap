/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:47:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/15 08:41:43 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_reverse(t_stack **stack, char *move)
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
	printf("%s\n", move);
}
