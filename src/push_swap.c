/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 07:44:26 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/11 17:30:21 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*ptr;

	if (argc < 2)
		ft_error("Error\nUsage: ./push_swap <arguments>");
	stack_a = ft_parse(argc, argv);
	if (!stack_a)
		ft_error("Error\nUsage: ./push_swap <numbers>");
	printf("\nList to sort = ");
	ptr = stack_a;
	while(ptr != NULL)
	{
		printf("%d ",ptr->number);
		ptr = ptr->next;
	}
	printf("\n\n>>>>> Parsing successful! ✅<<<<<\n\n");
	ft_free_stack(&stack_a);
	return (0);
}
