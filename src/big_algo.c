/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 08:37:39 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/20 15:46:58 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
TO DO :
	bring_b_back = 
	* ft_move (code all moves with actions)
	big_algo = 
	* rotate a until sorted
*/

void	ft_choose_move(t_stack *stack)
{
	t_lst	*ptr ;
	int		total;
	int		actions;

	ptr = stack->b;
	actions = INT_MAX;
	while (ptr)
	{
		total = (ft_absolute_value(ptr->nb_actions_lst_a)
				+ ft_absolute_value(ptr->nb_actions_lst_b));
		/*intégrer les valeurs absolues en tant qu'élément de structure pour rendre
		la lecture plus facile*/
		if (total < ft_absolute_value(actions))
		{
			actions = total;
			stack->actions_a = ptr->nb_actions_lst_a;
			stack->actions_b = ptr->nb_actions_lst_b;
		}
		ptr = ptr->next;
	}
}

void	ft_nb_actions(t_stack *stack)
{
	t_lst	*lst_b;

	lst_b = stack->b;
	while (lst_b)
	{
		lst_b->nb_actions_lst_a = lst_b->goal_pos;
		lst_b->nb_actions_lst_b = lst_b->pos;
		lst_b = lst_b->next;
	}
}

void	ft_bring_b_back(t_stack *stack, t_move *move)
{
	(void) move;
//	ft_push(&stack->b, &stack->a, move->push_a);
	ft_position(stack);
	ft_nb_actions(stack);
	ft_choose_move(stack);
//	ft_move(stack);
}

void	ft_pre_sorting_big(t_stack *stack, t_move *move)
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
}

void	ft_big_algo(t_stack *stack, t_move *move)
{
	ft_pre_sorting_big(stack, move);
	ft_three_algo(stack, &stack->a, move);
	ft_bring_b_back(stack, move);
//	ft_reset(stack, move);
}
