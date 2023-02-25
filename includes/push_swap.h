/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:10:07 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/25 08:44:45 by gwenolalero      ###   ########.fr       */
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
}					t_move;

typedef struct s_lst
{
	int				index;
	int				number;
	int				pos;
	int				goal_pos;
	int				actions_a;
	int				actions_b;
	int				abs_actions_a;
	int				abs_actions_b;
	struct s_lst	*prev;
	struct s_lst	*next;
}					t_lst;

typedef struct s_stack
{
	t_lst			*a;
	t_lst			*b;
	int				actions_a;
	int				actions_b;
	int				size_total;
	int				median_a;
}					t_stack;

/* ----------------INDEX---------------- */
int		ft_find_index_max(t_lst *lst);
int		ft_find_index_min(t_lst *lst);
void	ft_index(t_lst *a, int size);

/* ----------------PARSING---------------- */
t_stack	*ft_parse(int argc, char **argv);

/* ----------------STRUCTURES---------------- */
void	ft_add_element_bottom(t_lst **a, t_lst *element);
t_lst	*ft_create_element(int value);
t_stack	*ft_create_stack(void);
void	ft_free_stack(t_stack **stack);
void	ft_free_lst(t_lst **lst);
t_lst	*ft_lst_last(t_lst *stack);
t_lst	*ft_lst_penultimate(t_lst *lst);
int		ft_lst_size(t_lst **lst);
int		ft_stack_size(t_stack **stack);

/* ----------------MOVEMENTS---------------- */
void	ft_push(t_lst **from, t_lst **to, char *move);
void	ft_ra(t_stack *stack, t_move *move);
void	ft_ra_rrb(t_stack *stack, t_move *move);
void	ft_rb(t_stack *stack, t_move *move);
void	ft_reverse(t_lst **lst, char *move);
void	ft_reverse_both(t_stack *stack, t_move *move);
void	ft_rotate(t_lst **lst, char *move);
void	ft_rotate_both(t_stack *stack, t_move *move);
void	ft_rra(t_stack *stack, t_move *move);
void	ft_rra_rb(t_stack *stack, t_move *move);
void	ft_rrb(t_stack *stack, t_move *move);
void	ft_swap(t_lst **lst, char *move);

/* ----------------SORTING---------------- */
void	ft_actions(t_stack *stack);
void	ft_big_algo(t_stack *stack, t_move *move);
int		ft_check_sorted(t_lst *lst);
void	ft_position(t_stack *stack);
void	ft_sort(t_stack *stack);
void	ft_three_algo(t_stack *stack, t_move *move);
int		main(int argc, char **argv);

/* ----------------UTILS---------------- */
int		ft_abs_val(int nb);
void	ft_error(char *error, t_stack **stack, char **tab);
int		ft_find_min(int nb1, int nb2);
t_move	*ft_write_moves(void);

#endif
