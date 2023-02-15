/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 08:56:22 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/15 09:44:51 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_stack **stack, char *move)
{
	int	swap;

/* 	if ((*stack)->size_total < 2)
		return ; */
	swap = (*stack)->number;
	(*stack)->number = (*stack)->next->number;
	(*stack)->next->number = swap;
	swap = (*stack)->index;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->index = swap;
	printf("%s\n", move);
}
