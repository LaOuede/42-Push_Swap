/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 08:56:22 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/13 14:08:55 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_stack **stack)
{
	int		swap;

	if (!stack || (*stack)->next == NULL)
		return ;
	swap = (*stack)->next->number;
	(*stack)->next->number = (*stack)->number;
	(*stack)->number = swap;
	swap = (*stack)->next->index;
	(*stack)->next->index = (*stack)->index;
	(*stack)->index = swap;
}
