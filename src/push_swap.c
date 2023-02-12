/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 07:44:26 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/12 13:49:27 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc < 2)
		ft_error("Error\nUsage: ./push_swap <arguments> ❌");
	stack_a = ft_parse(argc, argv);
	if (!stack_a)
		ft_error("Error\nUsage: ./push_swap <numbers> ❌");
	printf("\nNumbers to sort = %d\n", ft_stack_size(stack_a));
	printf("\nList to sort = ");
	while (stack_a != NULL)
	{
		printf("%d ",stack_a->number);
		stack_a = stack_a->next;
	}
	printf("\n\n>>>>> Parsing successful! ✅<<<<<\n\n");
	ft_free_stack(&stack_a);
	return (0);
}
