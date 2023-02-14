/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 07:44:26 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/14 16:31:26 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*Main Parsing*/
/* int	main(int argc, char **argv)
{
	t_stack	*tmp;
	t_stack	*stack_a;

	if (argc < 2)
		ft_error("Error\nUsage: ./push_swap <arguments> ❌", &stack_a, 0);
	stack_a = ft_parse(argc, argv);
	printf("\nNumbers to sort = %d\n", stack_a->size_total);
	tmp = stack_a;
	printf("\nList to sort = ");
	while (tmp != NULL)
	{
		printf("%d ", tmp->number);
		tmp = tmp->next;
	}
	printf("\n\n>>>>> Parsing successful!✅ <<<<<\n\n");
	ft_free_stack(&stack_a);
	return (0);
} */

/*main index*/
/* int	main(int argc, char **argv)
{
	t_stack	*tmp;
	t_stack	*stack_a;

	if (argc < 2)
		ft_error("Error\nUsage: ./push_swap <arguments> ❌", &stack_a, 0);
	stack_a = ft_parse(argc, argv);
	printf("\nNumbers to sort = %d\n", stack_a->size_total);
	ft_index(stack_a,  stack_a->size_total);
	tmp = stack_a;
	printf("\nList to sort = ");
	while (tmp != NULL)
	{
		printf("%d ", tmp->number);
		tmp = tmp->next;
	}
	tmp = stack_a;
	printf("\nList index   = ");
	while (tmp != NULL)
	{
		printf("%d ", tmp->index);
		tmp = tmp->next;
	}
	printf("\n\n>>>>> Index completed!✅ <<<<<\n\n");
	ft_free_stack(&stack_a);
	return (0);
} */

/*Main Move*/
int	main(int argc, char **argv)
{
	t_stack	*tmp;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		ft_error("Error\nUsage: ./push_swap <arguments> ❌", &stack_a, 0);
	stack_a = ft_parse(argc, argv);
	stack_b = NULL;
	ft_index(stack_a, stack_a->size_total);
	printf("\nNumbers to sort = %d\n\n", stack_a->size_total);
	printf("\nList of movements =\n");
	ft_sort(stack_a, stack_b);
	tmp = stack_a;
	printf("\nStack_a = ");
	while (tmp != NULL)
	{
		printf("%d ", tmp->number);
		tmp = tmp->next;
	}
	printf("\n");
	printf("\nStack_b = ");
	tmp = stack_b;
	while (tmp != NULL)
	{
		printf("%d ", tmp->number);
		tmp = tmp->next;
	}
	printf("\n\n");
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}
