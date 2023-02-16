/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:17:25 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/16 17:04:31 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_five_algo(t_stack *stack, t_move *move)
{
	ft_pre_sorting(stack, move);
	if (ft_lst_size(&stack->a) == 3)
		ft_three_algo(stack, &stack->a, move);
	else if (stack->a->index > stack->a->next->index)
		ft_swap(&stack->a, move->swap_a);
	if (stack->b->index < stack->b->next->index)
		ft_swap(&stack->b, move->swap_b);
	while (stack->b)
		ft_push(&stack->b, &stack->a, move->push_a);
}

void	ft_three_algo(t_stack *stack, t_lst **lst_a, t_move *move)
{
	int	max;

	max = ft_find_index_max(stack->a);
	if ((*lst_a)->index == max)
		ft_rotate(&(*lst_a), move->rotate_a);
	if ((*lst_a)->next->index == max)
		ft_reverse(&(*lst_a), move->reverse_a);
	if ((*lst_a)->next->next->index == max && (*lst_a)->index > (*lst_a)->next->index)
		ft_swap(&(*lst_a), move->swap_a);
}

int	ft_check_sorted(t_lst *lst)
{
	while (lst->next != NULL)
	{
		if (lst->next->number < lst->number)
			return (F);
		lst = lst->next;
	}
	printf("\n>>>>> Already sorted!😎 <<<<<\n\n");
	return (T);
}

void	ft_sort(t_stack *stack)
{
	t_move	*move;

	move = ft_write_moves();
	if (ft_check_sorted(stack->a) == T)
		exit(EXIT_SUCCESS);
	if (stack->size_total == 2)
		ft_swap(&stack->a, move->swap_a);
	else if (stack->size_total == 3)
		ft_three_algo(stack, &stack->a, move);
	else if (stack->size_total > 3)
		ft_five_algo(stack, move);
	free(move);
}
