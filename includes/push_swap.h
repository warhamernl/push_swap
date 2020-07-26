/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 09:21:47 by mlokhors       #+#    #+#                */
/*   Updated: 2019/12/18 20:27:50 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "shared.h"
# define UP 1
# define DOWN 2
# define UPDOWN 3
# define ORDER 0
# define REV_ORDER 1

enum					e_operation
{
	E_SA = 0,
	E_SB = 1,
	E_SS = 2,
	E_PB = 3,
	E_PA = 4,
	E_RA = 5,
	E_RB = 6,
	E_RR = 7,
	E_RRA = 8,
	E_RRB = 9,
	E_RRR = 10
};

typedef struct	s_distance
{
	t_numbers	*rev_node;
	int			type_runner;
	int			path;
	int			save_i;
	int			i;
}				t_distance;

typedef struct	s_side_function_pointer
{
	int			i;
	int			rotate_double;
	int			rotate_single;
	int			rotate_rev_single;
	int			push;
}				t_side_function_pointer;

typedef struct	s_info
{
	int			*amount_1;
	int			*amount_2;
	int			*init_max;
	int			*init_min;
	int			order;
	t_numbers	**stack_1;
	t_numbers	**stack_2;
}				t_info;

typedef struct	s_direction_sort
{
	int			end_amount;
	int			(*sort)(t_numbers **stack, int stack_amount);
	int			*stack_amount;
	t_numbers	**stack;
}				t_direction_sort;

typedef	struct	s_keychain
{
	int			list_count;
	t_key		*instructions;
}				t_keychain;

void			set_target_1(t_numbers **runner_1, t_numbers *runner_2,
				int amount, int from_start);
void			ps_free_operation(t_key *move, int amount);
void			ps_set_sort_stack_to_rev(t_stacks *stacks,
					t_direction_sort *sort, int limit);
void			ps_set_sort_stack_to_in_order(t_stacks *stacks,
					t_direction_sort *sort, int limit);
void			ps_excute_up_or_down(t_stacks *stacks, t_keychain *moves,
				t_numbers *runner, t_info *info);
void			ps_search_for_lowest_distance(t_distance *distance,
				t_numbers *runner_down, t_numbers *runner_up, t_info *info);
void			ps_set_small_stack_targets(t_numbers **stack, int amount);
void			ps_init_up_functions(t_side_function_pointer *functions,
				t_numbers *runner, int which_stack);
void			ps_shift_stack(t_stacks *stacks, t_keychain *moves);
void			ps_search_and_do_shortest_distance(t_info *info,
				t_stacks *stacks, t_keychain *moves);
void			ps_calculate_distance(t_info *info);
void			ps_big_sorting(t_stacks *stacks, t_keychain *moves,
				t_direction_sort *sort);
int				ps_is_rev_sorted(t_numbers **stack, int stack_amount);
void			ps_brute_force(t_stacks *stacks, t_keychain *moves,
				t_direction_sort *sort);
void			ps_add_instruction_and_operations(t_stacks *stacks,
				t_keychain *keys, int operation);
void			ps_release_last_instruction(t_stacks *stacks,
				t_keychain *keys, int operation);
void			ps_freeing_stacks(t_stacks *stacks,
				t_keychain *moves);
void			ps_error_with_list(t_stacks *stacks, t_keychain *moves);

#endif
