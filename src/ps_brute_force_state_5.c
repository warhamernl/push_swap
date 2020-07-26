/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_brute_force_state_5.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 07:26:53 by mlokhors       #+#    #+#                */
/*   Updated: 2019/12/18 19:55:35 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "brute_force.h"

int			ps_brute_force_state_5_force(t_stacks *stacks,
			t_keychain *moves, int layer, t_direction_sort *sort)
{
	const int	possible_moves[4] = {E_SB, E_PA, E_RB, E_RRB};
	int			i;
	int			ret;

	ret = 0;
	i = 0;
	while (i < 4 && layer > 0)
	{
		ps_add_instruction_and_operations(stacks, moves, possible_moves[i]);
		ret = ps_brute_force_decision_force(stacks, moves, layer - 1, sort);
		if (ret == 0)
			return (0);
		ps_release_last_instruction(stacks, moves, possible_moves[i]);
		i++;
	}
	return (1);
}

int			ps_brute_force_state_5(t_stacks *stacks, t_keychain *moves,
			t_direction_sort *sort)
{
	const int	possible_moves[4] = {E_SB, E_PA, E_RB, E_RRB};
	int			i;
	int			ret;

	ret = 0;
	i = 0;
	while (i < 4)
	{
		ps_add_instruction_and_operations(stacks, moves, possible_moves[i]);
		if (sort->sort(sort->stack, *sort->stack_amount) == 1 &&
			*sort->stack_amount == sort->end_amount)
			return (0);
		ps_release_last_instruction(stacks, moves, possible_moves[i]);
		i++;
	}
	return (1);
}
