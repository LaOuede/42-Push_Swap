/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:10:07 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/21 14:25:31 by gle-roux         ###   ########.fr       */
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
	int				median_b;
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
void	ft_reverse_both(t_stack *stack, t_move *move);
void	ft_rrr(t_lst **lst);
void	ft_rotate_both(t_stack *stack, t_move *move);
void	ft_rr(t_lst **lst);
void	ft_move(t_stack *stack, t_move *move);
void	ft_ra(t_stack *stack, t_move *move);
void	ft_rb(t_stack *stack, t_move *move);
void	ft_rra(t_stack *stack, t_move *move);
void	ft_rrb(t_stack *stack, t_move *move);

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
//void	ft_get_pos(t_lst *lst);
void	ft_get_pos(t_lst *lst, int	size);
void	ft_position(t_stack *stack);
void	ft_find_goal_pos(t_stack *stack);
void	ft_move_cost(t_lst *lst);
int		ft_abs_val(int nb);
void	ft_reset(t_stack *stack, t_move *move);

/* ----------------UTILS---------------- */
void	ft_error(char *error, t_stack **stack, char **tab);

void	ft_add_element_front(t_lst **lst, t_lst *element);

#endif

/* 	while (i++ < 12)
	{
		ft_position(stack);
		ft_nb_actions(stack);
		ft_choose_move(stack);
		ft_move(stack, move);
		printf("\n>>>>> Move %d ok ✅ <<<<<<\n\n", i);
	} */