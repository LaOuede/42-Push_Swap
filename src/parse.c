/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:24:30 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/16 15:06:53 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_check_duplicates(t_stack *stack, t_lst *a)
{
	t_lst	*element_a;
	t_lst	*element_b;

	element_a = a->next;
	while (element_a->next != NULL)
	{
		element_b = element_a->next;
		while (element_b->next != NULL)
		{
			if (element_a->number == element_b->number)
				ft_error("Error\nUsage: ./push_swap <duplicates> ❌", &stack, 0);
			element_b = element_b->next;
		}
		if (element_b->next == NULL && element_a->number == element_b->number)
			ft_error("Error\nUsage: ./push_swap <duplicates> ❌", &stack, 0);
		element_a = element_a->next;
	}
}

void	ft_parse_args(int argc, char **argv, t_stack *stack)
{
	int			i;
	long int	nb;

	i = 1;
	while (i < argc)
	{
		if (ft_isnumber(argv[i]) == F)
			ft_error("Error\nUsage: ./push_swap <numbers> ❌", &stack, 0);
		nb = ft_atol(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			ft_error("Error\nUsage: ./push_swap <integers> ❌", &stack, 0);
		ft_add_element_bottom(&stack->a, ft_create_element((int)nb));
		stack->size_total++;
		i++;
	}
}

void	ft_parse_string(char *s, t_stack *stack)
{
	int			i;
	long int	nb;
	char		**tab_nb;

	tab_nb = ft_split(s, ' ');
	i = 0;
	if (tab_nb[i] == NULL)
		ft_error("Error\nUsage: ./push_swap <numbers> ❌", &stack, tab_nb);
	while (tab_nb[i])
	{	
		if (ft_isnumber(tab_nb[i]) == F)
			ft_error("Error\nUsage: ./push_swap <numbers> ❌", &stack, tab_nb);
		nb = ft_atol(tab_nb[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			ft_error("Error\nUsage: ./push_swap <integers> ❌", &stack, tab_nb);
		ft_add_element_bottom(&stack->a, ft_create_element((int)nb));
		stack->size_total++;
		i++;
	}
	ft_free_tab(tab_nb);
}

t_stack	*ft_parse(int argc, char **argv)
{
	t_stack	*stack_parse;

	stack_parse = ft_create_stack();
	if (argc == 2)
		ft_parse_string(argv[1], stack_parse);
	else if (argc > 2)
		ft_parse_args(argc, argv, stack_parse);
	if (stack_parse->size_total > 1)
		ft_check_duplicates(stack_parse, stack_parse->a);
	return (stack_parse);
}
