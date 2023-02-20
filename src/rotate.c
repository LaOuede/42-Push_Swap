/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:47:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/20 10:31:15 by gle-roux         ###   ########.fr       */
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
