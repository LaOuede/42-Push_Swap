/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 07:44:26 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/20 15:39:04 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*Main Parsing*/
/* int	main(int argc, char **argv)
{
	t_lst	*tmp;
	t_stack	*stack;

	if (argc < 2)
		ft_error("Error\nUsage: ./push_swap <arguments> ❌", &stack, 0);
	stack = ft_parse(argc, argv);
	printf("\nNumbers to sort = %d\n", stack->size_total);
	tmp = stack->a;
	printf("\nList to sort = ");
	while (tmp != NULL)
	{
		printf("%d ", tmp->number);
		tmp = tmp->next;
	}
	printf("\n\n>>>>> Parsing successful!✅ <<<<<\n\n");
	ft_free_stack(&stack);
	return (0);
} */

/*main index*/
/* int	main(int argc, char **argv)
{
	t_lst	*tmp;
	t_stack	*stack;

	if (argc < 2)
		ft_error("Error\nUsage: ./push_swap <arguments> ❌", &stack, 0);
	stack = ft_parse(argc, argv);
	printf("\nNumbers to sort = %d\n", stack->size_total);
	ft_index(stack->a, stack->size_total);
	tmp = stack->a;
	printf("\nList to sort = ");
	while (tmp != NULL)
	{
		printf("%d ", tmp->number);
		tmp = tmp->next;
	}
	tmp = stack->a;
	printf("\nList index   = ");
	while (tmp != NULL)
	{
		printf("%d ", tmp->index);
		tmp = tmp->next;
	}
	printf("\n\n>>>>> Index completed!✅ <<<<<\n\n");
	ft_free_stack(&stack);
	return (0);
} */

/*Main Move*/
int	main(int argc, char **argv)
{
	t_lst	*tmp;
	t_stack	*stack;
	t_stack	*ptr;

	if (argc >= 2)
	{
		stack = ft_parse(argc, argv);
		printf("\nNumbers to sort = %d\n", stack->size_total);
		ft_index(stack->a, stack->size_total);
		printf("\nList of movements =\n");
		ft_sort(stack);
		ptr = stack;
		tmp = stack->a;
		printf("\nStack_a numbers = ");
		while (tmp != NULL)
		{
			printf("%d ", tmp->number);
			tmp = tmp->next;
		}
		tmp = stack->a;
		printf("\nStack_a index = ");
		while (tmp != NULL)
		{
			printf("%d ", tmp->index);
			tmp = tmp->next;
		}
		tmp = stack->a;
		printf("\nStack_a pos = ");
		while (tmp != NULL)
		{
			printf("%d ", tmp->pos);
			tmp = tmp->next;
		}
		printf("\n");
		printf("\nStack_b numbers = ");
		tmp = stack->b;
		while (tmp != NULL)
		{
			printf("%d ", tmp->number);
			tmp = tmp->next;
		}
		printf("\nStack_b index = ");
		tmp = stack->b;
		while (tmp != NULL)
		{
			printf("%d ", tmp->index);
			tmp = tmp->next;
		}
		printf("\nStack_b goal_pos = ");
		tmp = stack->b;
		while (tmp != NULL)
		{
			printf("%d ", tmp->goal_pos);
			tmp = tmp->next;
		}
		printf("\nStack_b pos = ");
		tmp = stack->b;
		while (tmp != NULL)
		{
			printf("%d ", tmp->pos);
			tmp = tmp->next;
		}
		printf("\nStack_b actions = ");
		tmp = stack->b;
		while (tmp != NULL)
		{
			printf("(%d / ", tmp->nb_actions_lst_b);
			printf("%d) ", tmp->nb_actions_lst_a);
			tmp = tmp->next;
		}
		printf("\n\nStack actions to do (aka cheapest move) = ");
		while (ptr != NULL)
		{
			printf("(%d / ", ptr->actions_a);
			printf("%d) ", ptr->actions_b);
			ptr = ptr->next;
		}
		tmp = stack->a;
		t_lst *end = NULL;
		printf("\n\nStack_a List forward = ");
		while (tmp != NULL)
		{
			printf("%d ", tmp->number);
			end = tmp;
			tmp = tmp->next;
		}
		printf("\n");
		printf("Stack_a List backward = ");
		while (end != NULL)
		{
			printf("%d ", end->number);
			end = end->prev;
		}
		tmp = stack->b;
		end = NULL;
		printf("\n\nStack_b List forward = ");
		while (tmp != NULL)
		{
			printf("%d ", tmp->number);
			end = tmp;
			tmp = tmp->next;
		}
		printf("\n");
		printf("Stack_b List backward = ");
		while (end != NULL)
		{
			printf("%d ", end->number);
			end = end->prev;
		}
		printf("\n\n>>>>> List sorted successfuly!✅ <<<<<\n\n");
		ft_free_lst(&stack->a);
		ft_free_lst(&stack->a);
		ft_free_stack(&stack);
	}
	return (0);
}

/* size->total pb need to create a new structure for global structure */
/* int	main(int argc, char **argv)
{
	t_stack	*tmp;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		ft_error("Error\nUsage: ./push_swap <arguments> ❌", &stack_a, 0);
	stack_a = ft_parse(argc, argv);
	stack_b = NULL;
	ft_index(stack_a, stack_a->size_total);
	//printf("\nstack_a->size_total = %d\n\n", stack_a->size_total);
	tmp = stack_a;
	printf("\nStack_a->size_total = ");
	while (tmp != NULL)
	{
		printf("%d ", tmp->size_total);
		tmp = tmp->next;
	}
	printf("\n");
	printf("\n\n");
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
} */

/*Main Positions*/
/* int	main(int argc, char **argv)
{
	t_lst	*tmp;
	t_stack	*stack;

	if (argc >= 2)
	{
		stack = ft_parse(argc, argv);
		printf("\nNumbers to sort = %d\n", stack->size_total);
		ft_index(stack->a, stack->size_total);
		printf("\nList of movements =\n");
		ft_sort(stack);
		tmp = stack->a;
		printf("\nStack_a = ");
		while (tmp != NULL)
		{
			printf("%d ", tmp->pos);
			tmp = tmp->next;
		}
		printf("\n");
		printf("\nStack_b = ");
		tmp = stack->b;
		while (tmp != NULL)
		{
			printf("%d ", tmp->pos);
			tmp = tmp->next;
		}
		printf("\n\n>>>>> List sorted successfuly!✅ <<<<<\n\n");
		ft_free_lst(&stack->a);
		ft_free_lst(&stack->a);
		ft_free_stack(&stack);
	}
	return (0);
} */