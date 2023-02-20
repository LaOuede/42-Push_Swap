/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:24:30 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/20 07:46:10 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_isnumber(char *argv)
{
	int	i;

	i = 0;
	if ((argv[i] == 43 || argv[i] == 45) && argv[i + 1] != '\0')
		i++;
	while (argv[i] && ft_isdigit(argv[i]) == 1)
		i++;
	if (ft_isdigit(argv[i]) == 0 && argv[i] != '\0')
		return (F);
	return (T);
}

void	ft_check_duplicates(t_stack *stack, t_lst *a)
{
	t_lst	*node_1;
	t_lst	*node_2;

	node_1 = a;
	while (node_1->next != NULL)
	{
		node_2 = node_1->next;
		while (node_2->next != NULL)
		{
			if (node_1->number == node_2->number)
				ft_error("Error\nUsage: ./push_swap <duplicates> ❌", &stack, 0);
			node_2 = node_2->next;
		}
		if (node_2->next == NULL && node_1->number == node_2->number)
			ft_error("Error\nUsage: ./push_swap <duplicates> ❌", &stack, 0);
		node_1 = node_1->next;
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
