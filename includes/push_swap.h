/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:10:07 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/11 09:21:40 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <limits.h>
# include <stdio.h>
# include <unistd.h>

/* ----------------STRUCTURE---------------- */
typedef enum flag
{
	F,
	T
}	t_flag;

typedef struct s_stack
{
	int				index;
	int				value;
	int				pos;
	int				goal_pos;
	int				cost_stack_a;
	int				cost_stack_b;
	int				size_a;
	int				size_b;
	int				size_total;
	int				median_a;
	int				median_b;
	struct s_stack	*next;
}					t_stack;

/* ----------------PARSING---------------- */
int		ft_isnumber(char *argv);
t_stack	*ft_parse(int argc, char **argv);

/* ----------------LINKED LISTS---------------- */
t_stack	*ft_create_element(int value);
void	ft_free_stack(t_stack **stack);
void	ft_add_element_bottom(t_stack **stack, t_stack *element);

/* ----------------MOVEMENTS---------------- */

/* ----------------SORTING---------------- */
int		main(int argc, char **argv);

/* ----------------MAJOR_ALGORITHME---------------- */

/* ----------------MINOR_ALGORITHME---------------- */

/* ----------------UTILS---------------- */
void	ft_error(char *error);

#endif
