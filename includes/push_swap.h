/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:10:07 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/17 15:49:52 by gwenolalero      ###   ########.fr       */
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

typedef struct s_lst
{
	int				index;
	int				number;
	int				pos;
	int				goal_pos;
	struct s_lst	*next;
}					t_lst;

typedef struct s_stack
{
	t_lst			*a;
	t_lst			*b;
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
void	ft_index(t_lst *a, int size);

/* ----------------PARSING---------------- */
int		ft_isnumber(char *argv);
void	ft_check_duplicates(t_stack *stack, t_lst *a);
t_stack	*ft_parse(int argc, char **argv);
void	ft_parse_string(char *s, t_stack *stack);
void	ft_parse_args(int argc, char **argv, t_stack *stack);
int		ft_stack_size(t_stack **stack);

/* ----------------LINKED LISTS---------------- */
void	ft_add_element_bottom(t_lst **a, t_lst *element);
//void	ft_del_first_element(t_lst **a);
t_stack	*ft_create_stack(void);
t_lst	*ft_create_element(int value);
void	ft_free_stack(t_stack **stack);
//void	ft_free_stack(t_stack *stack);
void	ft_lst_clear(t_lst **lst, void (*del)(void *));
void	ft_free_lst(t_lst **lst);
int		ft_lst_size(t_lst **lst);

/* ----------------MOVEMENTS---------------- */
void	ft_push(t_lst **from, t_lst **to, char *move);
void	ft_reverse(t_lst **lst, char *move);
void	ft_rotate(t_lst **lst, char *move);
t_lst	*ft_lst_last(t_lst *stack);
t_lst	*ft_lst_penultimate(t_lst *lst);
void	ft_swap(t_lst **lst, char *move);
t_move	*ft_write_moves(void);

/* ----------------SORTING---------------- */
int		ft_check_sorted(t_lst *lst);
int		main(int argc, char **argv);

/* ----------------FIVE_ALGORITHM---------------- */
void	ft_five_algo(t_stack *stack, t_move *move);
void	ft_pre_sorting(t_stack *stack, t_move *move);

/* ----------------THREE_ALGORITHM---------------- */
void	ft_sort(t_stack *stack);
int		ft_find_index_max(t_lst *lst);
int		ft_find_index_min(t_lst *lst);
void	ft_three_algo(t_stack *stack, t_lst **lst_a, t_move *move);

/* ----------------BIG_ALGORITHM---------------- */
void	ft_big_algo(t_stack *stack, t_move *move);
void	ft_pre_sorting_big(t_stack *stack, t_move *move);
void	ft_bring_b_back(t_stack *stack, t_move *move);
void	ft_get_pos(t_lst *lst);
void	ft_position(t_stack *stack);
void	ft_find_goal_pos(t_stack *stack);
void	ft_move_cost(t_lst *lst);

/* ----------------UTILS---------------- */
void	ft_error(char *error, t_stack **stack, char **tab);

#endif
