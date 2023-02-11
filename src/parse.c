/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:24:30 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/11 17:36:48 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_parse_args(int argc, char **argv, t_stack *stack)
{
	int			i;
	long int	nb;

	i = 1;
	while (i < argc)
	{
		if (ft_isnumber(argv[i]) == F)
			ft_error("Error\nUsage: ./push_swap <numbers>");
		nb = ft_atol(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			ft_error("Error\nUsage: ./push_swap <integers>");
		ft_add_element_bottom(&stack, ft_create_element((int)nb));
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
	while (tab_nb[i])
	{
		if (ft_isnumber(tab_nb[i]) == F)
			ft_error("Error\nUsage: ./push_swap <numbers>");
		nb = ft_atol(tab_nb[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			ft_error("Error\nUsage: ./push_swap <integer>");
		ft_add_element_bottom(&stack, ft_create_element((int)nb));
		stack->size_total++;
		i++;
	}
	ft_free_tab(tab_nb);
}

t_stack	*ft_parse(int argc, char **argv)
{
	t_stack	*stack_parse;

	stack_parse = ft_create_element(666);
	if (!stack_parse)
		ft_error("Error\n");
	if (argc == 2)
		ft_parse_string(argv[1], stack_parse);
	else if (argc > 2)
		ft_parse_args(argc, argv, stack_parse);
	if (stack_parse->size_total == 0)
		ft_error("Error\nUsage: ./push_swap <numbers>");
	ft_del_first_node(&stack_parse);
	return (stack_parse);
}
