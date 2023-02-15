/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:14:30 by gwenolalero       #+#    #+#             */
/*   Updated: 2023/02/15 09:41:05 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_create_element(int nb)
{
	t_stack	*new_element;

	new_element = ft_calloc(sizeof * new_element, 1);
	if (!new_element)
		return (NULL);
	new_element->index = -1;
	new_element->number = nb;
	new_element->pos = -1;
	new_element->goal_pos = -1;
	new_element->cost_stack_a = -1;
	new_element->cost_stack_b = -1;
	new_element->size_a = -1;
	new_element->size_b = -1;
	new_element->size_total = 0;
	new_element->median_a = -1;
	new_element->median_b = -1;
	new_element->next = NULL;
	return (new_element);
}

void	ft_add_element_bottom(t_stack **stack, t_stack *element)
{
	t_stack	*last;

	if (!element)
		return ;
	if (!*stack)
	{
		*stack = element;
		return ;
	}
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = element;
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*ptr;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		ptr = (*stack)->next;
		free(*stack);
		*stack = ptr;
	}
	*stack = NULL;
}

void	ft_free_move(t_stack **stack)
{
	t_stack	*ptr;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		ptr = (*stack)->next;
		free(*stack);
		*stack = ptr;
	}
	*stack = NULL;
}

/* void	ft_free_stack(t_stack *stack)
{
	int		i;
	t_stack	*ptr;
	t_stack	*delete;

	if (!stack)
		return ;
	i = -1;
	ptr = stack;
	while (i++ < stack->size_total)
	{
		delete = ptr;
		ptr = ptr->next;
		free(delete);
	}
	free(stack);
} */

void	ft_del_first_element(t_stack **stack)
{
	t_stack	*ptr;

	if (!stack || !*stack)
		return ;
	ptr = *stack;
	*stack = (*stack)->next;
	free(ptr);
}

int	ft_stack_size(t_stack **stack)
{
	int		size;
	t_stack	*ptr;

	size = 0;
	ptr = *stack;
	if (!stack)
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
