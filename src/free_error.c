/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 08:23:42 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/24 18:38:25 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(char *error, t_stack **stack, char **tab)
{
	if ((*stack)->a)
		ft_free_lst(&(*stack)->a);
	if ((*stack)->b)
		ft_free_lst(&(*stack)->b);
	if (stack)
		ft_free_stack(stack);
	if (tab)
		ft_free_tab(tab);
	write(STDERR_FILENO, error, ft_strlen(error));
	exit(EXIT_FAILURE);
}

void	ft_free_stack(t_stack **stack)
{
	if (!stack || !*stack)
		return ;
	free(*stack);
	*stack = NULL;
}

void	ft_free_lst(t_lst **lst)
{
	t_lst	*ptr;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		ptr = (*lst)->next;
		free(*lst);
		*lst = ptr;
	}
	*lst = NULL;
}
