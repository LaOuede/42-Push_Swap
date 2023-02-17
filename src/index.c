/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:39:22 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/17 10:39:56 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_index(t_lst *a, int size)
{
	int		i;
	t_lst	*max;
	t_lst	*ptr;

	max = NULL;
	ptr = a;
	while (size > 0)
	{
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
		ptr = a;
		size--;
	}
}

int	ft_find_index_max(t_lst *lst)
{
	int		max;
	t_lst	*ptr;

	max = 0;
	ptr = lst;
	while (ptr != NULL)
	{
		if (ptr->index > max)
		{
			max = ptr->index;
		}
		ptr = ptr->next;
	}
	return (max);
}

int	ft_find_index_min(t_lst *lst)
{
	int		min;
	t_lst	*ptr;

	min = INT_MAX;
	ptr = lst;
	while (ptr != NULL)
	{
		if (ptr->index < min)
		{
			min = ptr->index;
		}
		ptr = ptr->next;
	}
	return (min);
}