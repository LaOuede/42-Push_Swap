/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:39:22 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/27 08:45:29 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*This functions gives an index to each number*/
void	ft_index(t_lst *lst, int size)
{
	int		landmark;
	t_lst	*max;
	t_lst	*ptr;

	max = NULL;
	ptr = lst;
	while (size > 0)
	{
		landmark = INT_MIN;
		while (ptr != NULL)
		{
			if ((landmark <= ptr->number) && ptr->index == -1)
			{
				landmark = ptr->number;
				max = ptr;
			}
			ptr = ptr->next;
		}
		max->index = size;
		ptr = lst;
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
