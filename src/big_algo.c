/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 08:37:39 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/21 15:43:56 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_reset(t_stack *stack, t_move *move)
{
	while (ft_check_sorted(stack->a) == 0)
	{
		if (stack->a->index < (ft_lst_size(&stack->a) / 2))
			ft_reverse(&stack->a, move->reverse_a);
		else
			ft_rotate(&stack->a, move->rotate_a);
	}
}

void	ft_move(t_stack *stack, t_move *move)
{
	while (stack->actions_a || stack->actions_b)
	{

		if (stack->actions_a > 0 && stack->actions_b > 0)
			ft_rotate_both(stack, move);
		else if (stack->actions_a < 0 && stack->actions_b < 0)
			ft_reverse_both(stack, move);
		else if (stack->actions_a > 0 && stack->actions_b == 0)
		{
			ft_rotate(&stack->a, move->rotate_a);
			stack->actions_a--;
		}
		else if (stack->actions_a == 0 && stack->actions_b > 0)
		{
			ft_rotate(&stack->b, move->rotate_b);
			stack->actions_b--;
		}
		else if (stack->actions_a < 0 && stack->actions_b == 0)
		{
			ft_reverse(&stack->a, move->reverse_a);
			stack->actions_a++;
		}
		else if (stack->actions_a == 0 && stack->actions_b < 0)
		{
			ft_reverse(&stack->b, move->reverse_b);
			stack->actions_b++;
		}
	}
	ft_push(&stack->b, &stack->a, move->push_a);
	printf("\n>>>>> Do move ok ✅ <<<<<<\n\n");
}

void	ft_choose_move(t_stack *stack)
{
	t_lst	*ptr ;
	int		total;
	int		actions;

	ptr = stack->b;
	actions = INT_MAX;
	while (ptr)
	{
		total = stack->b->abs_actions_a + stack->b->abs_actions_b;
		if (total < actions)
		{
			actions = total;
			stack->actions_a = ptr->actions_a;
			stack->actions_b = ptr->actions_b;
		}
		ptr = ptr->next;
	}
	printf("\n>>>>> Choose move ok ✅ <<<<<<\n\n");
}

void	ft_nb_actions(t_stack *stack)
{
	t_lst	*lst_b;

	lst_b = stack->b;
	while (lst_b)
	{
		lst_b->actions_a = lst_b->goal_pos;
		lst_b->actions_b = lst_b->pos;
		lst_b->abs_actions_a = ft_abs_val(lst_b->actions_a);
		lst_b->abs_actions_b = ft_abs_val(lst_b->actions_b);
		lst_b = lst_b->next;
	}
	printf("\n>>>>> Nb actions ok ✅ <<<<<<\n\n");
}

/*void	ft_pre_sorting_big(t_stack *stack, t_move *move)
{
	int	push;
	int	median;

	push = 0;
	median = (stack->size_total / 2);
	while (push < median)
	{
		if (stack->a->index <= median)
		{
			ft_push(&stack->a, &stack->b, move->push_b);
				push++;
		}
		else
			ft_rotate(&stack->a, move->rotate_a);
	}
	if (ft_lst_size(&stack->a) > 3)
	{
		while (ft_lst_size(&stack->a) > 3)
		{
			if (stack->a->index < (stack->size_total - 2))
				ft_push(&stack->a, &stack->b, move->push_b);
			else
				ft_rotate(&stack->a, move->rotate_a);
		}
	}
	printf("\n>>>>> Pre-sorting ok ✅ <<<<<<\n\n");
}*/

void	ft_pre_sorting_big(t_stack *stack, t_move *move)
{
	int	push;
	int	repere;

	push = 0;
	repere = ((stack->size_total / 5));
	while (push < repere)
	{
		if (stack->a->index <= repere)
		{
			ft_push(&stack->a, &stack->b, move->push_b);
				push++;
		}
		else
			ft_rotate(&stack->a, move->rotate_a);
	}
	repere = ((stack->size_total / 2.5));
	while (push < repere)
	{
		if (stack->a->index <= repere)
		{
			ft_push(&stack->a, &stack->b, move->push_b);
				push++;
		}
		else
			ft_rotate(&stack->a, move->rotate_a);
	}
	repere = ((stack->size_total / 1.65));
	while (push < repere)
	{
		if (stack->a->index <= repere)
		{
			ft_push(&stack->a, &stack->b, move->push_b);
				push++;
		}
		else
			ft_rotate(&stack->a, move->rotate_a);
	}
	repere = ((stack->size_total / 1.25));
	while (push < repere)
	{
	if (stack->a->index <= repere)
	{
		ft_push(&stack->a, &stack->b, move->push_b);
			push++;
	}
	else
		ft_rotate(&stack->a, move->rotate_a);
	}
	if (ft_lst_size(&stack->a) > 3)
	{
		while (ft_lst_size(&stack->a) > 3)
		{
			if (stack->a->index < (stack->size_total - 2))
				ft_push(&stack->a, &stack->b, move->push_b);
			else
				ft_rotate(&stack->a, move->rotate_a);
		}
	}
}

void	ft_big_algo(t_stack *stack, t_move *move)
{
	ft_pre_sorting_big(stack, move);
	ft_three_algo(stack, &stack->a, move);
	while (stack->b)
	{
		ft_position(stack);
		ft_nb_actions(stack);
		ft_choose_move(stack);
		ft_move(stack, move);
	}
	ft_reset(stack, move);
}
