/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:47:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/21 14:58:21 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	ft_rr(t_lst **lst)
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
}

void	ft_rotate_both(t_stack *stack, t_move *move)
{
	ft_rr(&stack->a);
	ft_rr(&stack->b);
	stack->actions_a--;
	stack->actions_b--;
	printf("%s\n", move->rotate);
}