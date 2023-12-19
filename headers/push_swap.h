/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:42:59 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/19 20:38:20 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "limits.h"

# include "../libft/libft.h"
# include "../printf/ft_printf.h"

// push_swap.c

void	insert_int_in_stack(t_list **stack_a, int argc, int i, char **argv);
void	sort_stack(t_list **stack_a, t_list **stack_b, t_list **operations);
void	print_operations(t_list *operations);

void	display_struct(t_list *lst, char data, char *text);

// sort_small_stack.c

void	sort_stack_of_2(t_list **stack_a, char order, t_list **operations);
void	sort_stack_of_3(t_list **stack_a, t_list **operations);
void	sort_stack_of_4_or_5(t_list **stack_a, t_list **operations);

// push_swap_algo.c

void	sort_big_stack(t_list **stack_a, t_list **operations);
t_list	*find_cheapest_number(t_list *stack_out, t_list *stack_in);

// count_move.c

int		count_move(t_list *lst, t_list *stack_out, t_list *stack_in);
int		find_index_previous_number(t_list *lst, t_list *stack);

// check_sorted_stack.c

int		is_sorted(t_list *stack_a);
int		is_sorted_not_ordered(t_list *stack_a);

// push_swap_algo_utils.c

t_list	*get_min(t_list *stack);
t_list	*get_max(t_list *stack);
void	move_lst_on_top(t_list **stack_a, t_list **operations, t_list *lst);
int		get_lst_index(t_list *stack_a, t_list *lst);

// operations_push.c

void	ft_push(t_list **stack_in, t_list **stack_out);
void	ft_pa(t_list **stack_a, t_list **stack_b, t_list **operations);
void	ft_pb(t_list **stack_b, t_list **stack_a, t_list **operations);

// operations_swap.c

void	ft_swap(t_list **stack);
void	ft_sa(t_list **stack_a, t_list **operations);
void	ft_sb(t_list **stack_b, t_list **operations);
void	ft_ss(t_list **stack_a, t_list **stack_b, t_list **operations);

// operations_rotate.c

void	ft_rotate(t_list **stack);
void	ft_ra(t_list **stack_a, t_list **operations);
void	ft_rb(t_list **stack_b, t_list **operations);
void	ft_rr(t_list **stack_a, t_list **stack_b, t_list **operations);

// operations_rotate.c

void	ft_reverse(t_list **stack);
void	ft_rra(t_list **stack_a, t_list **operations);
void	ft_rrb(t_list **stack_b, t_list **operations);
void	ft_rrr(t_list **stack_a, t_list **stack_b, t_list **operations);

// input_validation.c

int		input_is_valid(int argc, char **argv);
int		string_is_valid(char *str);
int		int_is_valid(char *str);
int		ints_are_uniq(t_list *stack_a);

// error.c

int		ft_error(void);

// safe_free.c

void	*free_strstr(char **numbers);
void	del(void *content);

#endif