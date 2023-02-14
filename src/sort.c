/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:17:25 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/14 16:35:55 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_check_sorted(t_stack *stack_a)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->next->number < stack_a->number)
			return (F);
		stack_a = stack_a->next;
	}
	printf("\n>>>>> Already sorted!😎 <<<<<\n\n");
	return (T);
}

void	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	if ((stack_a->size_total == 2) && (ft_check_sorted(stack_a) == F))
		ft_sa(&stack_a);
}
