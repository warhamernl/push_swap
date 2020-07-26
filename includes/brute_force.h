/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   brute_force.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 06:35:28 by mlokhors       #+#    #+#                */
/*   Updated: 2019/12/18 19:59:05 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRUTE_FORCE_H
# define BRUTE_FORCE_H
# include "push_swap.h"

int			ps_brute_force_state_5_force(t_stacks *stacks,
			t_keychain *moves, int layer, t_direction_sort *sort);
int			ps_brute_force_state_5(t_stacks *stacks, t_keychain *moves,
			t_direction_sort *sort);
int			ps_brute_force_state_4_force(t_stacks *stacks,
			t_keychain *moves, int layer, t_direction_sort *sort);
int			ps_brute_force_state_4(t_stacks *stacks, t_keychain *moves,
			t_direction_sort *sort);
int			ps_brute_force_state_3_force(t_stacks *stacks,
			t_keychain *moves, int layer, t_direction_sort *sort);
int			ps_brute_force_state_3(t_stacks *stacks, t_keychain *moves,
			t_direction_sort *sort);
int			ps_brute_force_state_2_force(t_stacks *stacks,
			t_keychain *moves, int layer, t_direction_sort *sort);
int			ps_brute_force_state_2(t_stacks *stacks, t_keychain *moves,
			t_direction_sort *sort);
int			ps_brute_force_state_1_force(t_stacks *stacks,
			t_keychain *moves, int layer, t_direction_sort *sort);
int			ps_brute_force_state_1(t_stacks *stacks, t_keychain *moves,
			t_direction_sort *sort);
int			ps_brute_force_decision_force(t_stacks *stacks,
			t_keychain *moves, int layer, t_direction_sort *sort);
int			ps_brute_force_decision_top(t_stacks *stacks, t_keychain *moves,
			t_direction_sort *sort);
int			ps_brute_force_descision(t_stacks *stacks,
			t_keychain *moves, int layer, t_direction_sort *sort);

#endif
