/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:14:30 by gwenolalero       #+#    #+#             */
/*   Updated: 2023/02/24 14:59:00 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_create_stack(void)
{
	t_stack	*new_stack;

	new_stack = ft_calloc(sizeof(*new_stack), 1);
	if (!new_stack)
		return (NULL);
	new_stack->actions_a = -1;
	new_stack->actions_b = -1;
	new_stack->size_total = 0;
	new_stack->median_a = -1;
	return (new_stack);
}

t_lst	*ft_create_element(int nb)
{
	t_lst	*new_element;

	new_element = ft_calloc(sizeof(*new_element), 1);
	if (!new_element)
		return (NULL);
	new_element->index = -1;
	new_element->number = nb;
	new_element->pos = 0;
	new_element->goal_pos = -1;
	new_element->landmark = INT_MIN;
	new_element->actions_a = 0;
	new_element->actions_b = 0;
	new_element->abs_actions_a = 0;
	new_element->abs_actions_b = 0;
	new_element->prev = NULL;
	new_element->next = NULL;
	return (new_element);
}

void	ft_add_element_bottom(t_lst **a, t_lst *element)
{
	t_lst	*last;

	if (!element)
		return ;
	if (*a == NULL)
	{
		*a = element;
		element->prev = NULL;
		return ;
	}
	last = *a;
	while (last->next != NULL)
		last = last->next;
	last->next = element;
	element->prev = last;
}

int	ft_lst_size(t_lst **lst)
{
	int		size;
	t_lst	*ptr;

	size = 0;
	ptr = *lst;
	if (!lst)
		return (0);
	while (ptr->next != NULL)
	{
		size++;
		ptr = ptr->next;
	}
	if (ptr->next == NULL)
		size++;
	return (size);
}
