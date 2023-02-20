/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:47:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/20 10:42:20 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_reverse(t_lst **lst, char *move)
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
	printf("%s\n", move);
}
