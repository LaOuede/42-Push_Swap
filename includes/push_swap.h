/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:10:07 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/15 09:40:15 by gwenolalero      ###   ########.fr       */
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

typedef struct s_move
{
	char			*push;
	char			*push_a;
	char			*push_b;
	char			*swap_a;
	char			*swap_b;
	char			*rotate;
	char			*rotate_a;
	char			*rotate_b;
	char			*reverse;
	char			*reverse_a;
	char			*reverse_b;
	struct s_move	*next;
}					t_move;

/* typedef struct s_lst
{
	int				index;
	int				number;
	struct s_lst	*next;
}					t_lst; */

typedef struct s_stack
{
/* 	t_lst			*a;
	t_lst			*b; */
	int				index;
	int				number;
	int				pos;
	int				goal_pos;
	int				cost_stack_a;
	int				cost_stack_b;
	int				size_a;
	int				size_b;
	int				size_total;
	int				median_a;
	int				median_b;
	int				sorted;
	struct s_stack	*next;
}					t_stack;

/* ----------------INDEX---------------- */
void	ft_index(t_stack *stack, int size);

/* ----------------PARSING---------------- */
int		ft_isnumber(char *argv);
void	ft_check_duplicates(t_stack *stack);
t_stack	*ft_parse(int argc, char **argv);
void	ft_parse_string(char *s, t_stack *stack);
void	ft_parse_args(int argc, char **argv, t_stack *stack);
int		ft_stack_size(t_stack **stack);

/* ----------------LINKED LISTS---------------- */
void	ft_add_element_bottom(t_stack **stack, t_stack *element);
void	ft_del_first_element(t_stack **stack);
t_stack	*ft_create_element(int value);
void	ft_free_stack(t_stack **stack);
//void	ft_free_stack(t_stack *stack);

/* ----------------MOVEMENTS---------------- */
void	ft_push(t_stack **from, t_stack **to, char *move);
void	ft_reverse(t_stack **stack, char *move);
void	ft_rotate(t_stack **stack, char *move);
t_stack	*ft_stack_last(t_stack *stack);
t_stack	*ft_stack_penultimate(t_stack *stack);
void	ft_swap(t_stack **stack, char *move);
t_move	*ft_write_moves(void);

/* ----------------SORTING---------------- */
int		ft_check_sorted(t_stack *stack_a);
int		main(int argc, char **argv);

/* ----------------MAJOR_ALGORITHME---------------- */

/* ----------------MINOR_ALGORITHME---------------- */
void	ft_sort(t_stack **stack_a, t_stack **stack_b);
int		ft_find_index_max(t_stack *stack);
void	ft_minor_algo(t_stack **stack_a, t_move *move);

/* ----------------UTILS---------------- */
void	ft_error(char *error, t_stack **stack, char **tab);

#endif
