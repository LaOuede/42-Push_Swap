/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 08:56:22 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/16 10:28:52 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_lst **lst, char *move)
{
	int	swap;

	if (!lst || (*lst)->next == NULL)
		return ;
	swap = (*lst)->number;
	(*lst)->number = (*lst)->next->number;
	(*lst)->next->number = swap;
	swap = (*lst)->index;
	(*lst)->index = (*lst)->next->index;
	(*lst)->next->index = swap;
	printf("%s\n", move);
}
