/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   synchro_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:47:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/27 10:20:42 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*These functions do basic rr and rrr moves but update the cost
at the same time.*/
static void	ft_rrr(t_lst **lst)
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
}

void	ft_reverse_both(t_stack *stack, t_move *move)
{
	ft_rrr(&stack->a);
	ft_rrr(&stack->b);
	stack->actions_a++;
	stack->actions_b++;
	ft_printf("%s\n", move->reverse);
}

static void	ft_rr(t_lst **lst)
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
	ft_printf("%s\n", move->rotate);
}
