/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:14:30 by gwenolalero       #+#    #+#             */
/*   Updated: 2023/02/20 14:34:09 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push(t_lst **from, t_lst **to, char *move)
{
	t_lst	*ptr;

	if (!(*from))
		return ;
	if ((*from)->next == NULL)
	{
		ft_add_element_front(to, (*from));
		(*from) = NULL;
		return ;
	}
	ptr = (*from)->next;
	ft_add_element_front(to, (*from));
	(*from) = ptr;
	(*from)->prev = NULL;
	printf("%s\n", move);
}


void	ft_add_element_front(t_lst **lst, t_lst *element)
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
