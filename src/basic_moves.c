/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:55:19 by gwenolalero       #+#    #+#             */
/*   Updated: 2023/02/24 15:12:08 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_add_element_front(t_lst **lst, t_lst *element)
{
	t_lst	*ptr;

	if (!element)
		return ;
	if (*lst == NULL)
	{
		*lst = element;
		element->next = NULL;
		return ;
	}
	ptr = *lst;
	ptr->prev = element;
	element->prev = NULL;
	element->next = *lst;
	*lst = element;
}

void	ft_push(t_lst **from, t_lst **to, char *move)
{
	t_lst	*ptr;

	if (!(*from))
		return ;
	if ((*from)->next == NULL)
	{
		ft_add_element_front(to, (*from));
		(*from) = NULL;
		printf("%s\n", move);
		return ;
	}
	ptr = (*from)->next;
	ft_add_element_front(to, (*from));
	(*from) = ptr;
	(*from)->prev = NULL;
	printf("%s\n", move);
}

void	ft_reverse(t_lst **lst, char *move)
{
	t_lst	*head;
	t_lst	*last;
	t_lst	*penultimate;

	last = ft_lst_last(*lst);
	penultimate = ft_lst_penultimate(*lst);
	head = *lst;
	*lst = last;
	(*lst)->next = head;
	last->prev = NULL;
	penultimate->next = NULL;
	head->prev = last;
	printf("%s\n", move);
}

void	ft_rotate(t_lst **lst, char *move)
{
	t_lst	*ptr;
	t_lst	*last;

	ptr = *lst;
	*lst = (*lst)->next;
	last = ft_lst_last(*lst);
	last->next = ptr;
	ptr->next = NULL;
	ptr->prev = last;
	(*lst)->prev = NULL;
	printf("%s\n", move);
}

void	ft_swap(t_lst **lst, char *move)
{
	int		swap;

	if (!lst || (*lst)->next == NULL)
		return ;
	swap = (*lst)->number;
	(*lst)->number = (*lst)->next->number;
	(*lst)->next->number = swap;
	swap = (*lst)->index;
	(*lst)->index = (*lst)->next->index;
	(*lst)->next->index = swap;
	printf("%s\n", move);
}
