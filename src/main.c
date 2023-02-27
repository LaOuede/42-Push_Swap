/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 07:44:26 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/27 08:18:50 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc >= 2)
	{
		stack = ft_parse(argc, argv);
		ft_index(stack->a, stack->size_total);
		ft_sort(stack);
		ft_free_lst(&stack->a);
		ft_free_lst(&stack->b);
		ft_free_stack(&stack);
	}
	return (0);
}
