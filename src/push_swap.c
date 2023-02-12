/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 07:44:26 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/12 18:19:42 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*tmp;
	t_stack	*stack_a;

	if (argc < 2)
		ft_error("Error\nUsage: ./push_swap <arguments> ❌");
	stack_a = ft_parse(argc, argv);
	tmp = stack_a;
	printf("\nNumbers to sort = %d\n", ft_stack_size(stack_a));
	printf("\nList to sort = ");
	while (tmp != NULL)
	{
		printf("%d ", tmp->number);
		tmp = tmp->next;
	}
	printf("\n\n>>>>> Parsing successful! ✅<<<<<\n\n");
	ft_free_stack(&stack_a);
	return (0);
}
