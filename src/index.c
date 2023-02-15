/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:39:22 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/15 09:00:12 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_index(t_stack *stack, int size)
{
	int		i;
	t_stack	*max;
	t_stack	*ptr;

	max = NULL;
	while (size > 0)
	{
		ptr = stack;
		i = INT_MIN;
		while (ptr != NULL)
		{
			if ((i <= ptr->number) && ptr->index == -1)
			{
				i = ptr->number;
				max = ptr;
			}
			ptr = ptr->next;
		}
		max->index = size;
		size--;
	}
}
