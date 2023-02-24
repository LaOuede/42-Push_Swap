/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:17:25 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/24 14:57:06 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_pre_sorting(t_stack *stack, t_move *move)
{
	int	push;

	push = 0;
	while (push < stack->median_a)
	{
		if (stack->a->index <= stack->median_a)
		{
			ft_push(&stack->a, &stack->b, move->push_b);
				push++;
		}
		else
			ft_rotate(&stack->a, move->rotate_a);
	}
}

static void	ft_five_algo(t_stack *stack, t_move *move)
{
	ft_pre_sorting(stack, move);
	if (ft_lst_size(&stack->a) == 3)
		ft_three_algo(stack, move);
	else if (stack->a->index > stack->a->next->index)
		ft_swap(&stack->a, move->swap_a);
	if (stack->b->index < stack->b->next->index)
		ft_swap(&stack->b, move->swap_b);
	while (stack->b)
		ft_push(&stack->b, &stack->a, move->push_a);
}

void	ft_three_algo(t_stack *stack, t_move *move)
{
	int	max;

	max = ft_find_index_max(stack->a);
	if (stack->a->index == max)
		ft_rotate(&stack->a, move->rotate_a);
	if (stack->a->next->index == max)
		ft_reverse(&stack->a, move->reverse_a);
	if (stack->a->next->next->index == max
		&& stack->a->index > stack->a->next->index)
		ft_swap(&stack->a, move->swap_a);
}

int	ft_check_sorted(t_lst *lst)
{
	t_lst	*ptr;

	ptr = lst;
	while (ptr->next != NULL)
	{
		if (ptr->next->number < ptr->number)
			return (F);
		ptr = ptr->next;
	}
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
		ft_three_algo(stack, move);
	else if (stack->size_total <= 5)
		ft_five_algo(stack, move);
	else
		ft_big_algo(stack, move);
	free(move);
}
