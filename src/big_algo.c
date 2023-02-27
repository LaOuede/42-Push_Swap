/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 08:37:39 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/27 08:52:02 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*This function brings bask the min index on top of a stack at the end of the
sorting part.*/
static void	ft_reset(t_stack *stack, t_move *move)
{
	while (ft_check_sorted(stack->a) == 0)
	{
		if (stack->a->index < (ft_lst_size(&stack->a) / 2))
			ft_reverse(&stack->a, move->reverse_a);
		else
			ft_rotate(&stack->a, move->rotate_a);
	}
}

/*This function does the moves needed regarding the action cost of a and b.*/
static void	ft_move(t_stack *stack, t_move *move)
{
	while (stack->actions_a || stack->actions_b)
	{
		if (stack->actions_a > 0 && stack->actions_b > 0)
			ft_rotate_both(stack, move);
		else if (stack->actions_a < 0 && stack->actions_b < 0)
			ft_reverse_both(stack, move);
		else if (stack->actions_a > 0 && stack->actions_b == 0)
			ft_ra(stack, move);
		else if (stack->actions_a == 0 && stack->actions_b > 0)
			ft_rb(stack, move);
		else if (stack->actions_a < 0 && stack->actions_b == 0)
			ft_rra(stack, move);
		else if (stack->actions_a == 0 && stack->actions_b < 0)
			ft_rrb(stack, move);
		else if (stack->actions_a > 0 && stack->actions_b < 0)
			ft_ra_rrb(stack, move);
		else if (stack->actions_a < 0 && stack->actions_b > 0)
			ft_rra_rb(stack, move);
	}
	ft_push(&stack->b, &stack->a, move->push_a);
}

/*This function pushes numbers from stack a to the top of stack b.*/
static void	ft_pre_sorting_big(t_stack *stack, t_move *move)
{
	int	landmark;

	landmark = 0;
	while (landmark < stack->median_a)
	{
		if (stack->a->index <= stack->median_a)
		{
			ft_push(&stack->a, &stack->b, move->push_b);
				landmark++;
		}
		else
			ft_rotate(&stack->a, move->rotate_a);
	}
	while (ft_lst_size(&stack->a) > 3)
		ft_push(&stack->a, &stack->b, move->push_b);
}

void	ft_big_algo(t_stack *stack, t_move *move)
{
	ft_pre_sorting_big(stack, move);
	ft_three_algo(stack, move);
	while (stack->b)
	{
		ft_position(stack);
		ft_actions(stack);
		ft_move(stack, move);
	}
	ft_reset(stack, move);
}
