/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:14:30 by gwenolalero       #+#    #+#             */
/*   Updated: 2023/02/17 11:52:53 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_create_stack(void)
{
	t_stack	*new_stack;

	new_stack = ft_calloc(sizeof * new_stack, 1);
	if (!new_stack)
		return (NULL);
	new_stack->cost_stack_a = -1;
	new_stack->cost_stack_b = -1;
	new_stack->size_a = -1;
	new_stack->size_b = -1;
	new_stack->size_total = 0;
	new_stack->median_a = -1;
	new_stack->median_b = -1;
	new_stack->next = NULL;
	return (new_stack);
}

t_lst	*ft_create_element(int nb)
{
	t_lst	*new_element;

	new_element = ft_calloc(sizeof * new_element, 1);
	if (!new_element)
		return (NULL);
	new_element->index = -1;
	new_element->number = nb;
	new_element->pos = -1;
	new_element->goal_pos = -1;
	new_element->next = NULL;
	return (new_element);
}

void	ft_add_element_bottom(t_lst **a, t_lst *element)
{
	t_lst	*last;

	if (!element)
		return ;
	if (!*a)
	{
		*a = element;
		return ;
	}
	last = *a;
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

void	ft_free_lst(t_lst **lst)
{
	t_lst	*ptr;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		ptr = (*lst)->next;
		free(*lst);
		*lst = ptr;
	}
	*lst = NULL;
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

/* void	ft_del_first_element(t_lst **a)
{
	t_lst	*ptr;

	if (!a || !*a)
		return ;
	ptr = *a;
	*a = (*a)->next;
	free(ptr);
} */

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

void	ft_lst_clear(t_lst **lst, void (*del)(void *))
{
	t_lst	*old_elem;

	if (!del)
		return ;
	while (*lst)
	{
		del(*lst);
		free((void *)(*lst));
		old_elem = *lst;
		*lst = old_elem->next;
		free(old_elem);
	}
	*lst = NULL;
}