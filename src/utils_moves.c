/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:21:23 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/21 14:25:17 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_move	*ft_write_moves(void)
{
	t_move	*moves;

	moves = ft_calloc(sizeof * moves, 1);
	if (!moves)
		return (NULL);
	moves->push = "ss";
	moves->push_a = "pa";
	moves->push_b = "pb";
	moves->swap_a = "sa";
	moves->swap_b = "sb";
	moves->rotate = "rr";
	moves->rotate_a = "ra";
	moves->rotate_b = "rb";
	moves->reverse = "rrr";
	moves->reverse_a = "rra";
	moves->reverse_b = "rrb";
	return (moves);
}

t_lst	*ft_lst_last(t_lst *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_lst	*ft_lst_penultimate(t_lst *lst)
{
	if (!lst)
		return (0);
	while (lst->next && lst->next->next != NULL)
		lst = lst->next;
	return (lst);
}
