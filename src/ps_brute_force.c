/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_brute_force.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 05:15:45 by mlokhors       #+#    #+#                */
/*   Updated: 2019/12/18 20:17:12 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "brute_force.h"

int		ps_brute_force_decision_top(t_stacks *stacks, t_keychain *moves,
	t_direction_sort *sort)
{
	if (stacks->b_amount == 0 && stacks->a_amount > 0)
		return (ps_brute_force_state_1(stacks, moves, sort));
	if (stacks->b_amount == 1 && stacks->a_amount > 0)
		return (ps_brute_force_state_2(stacks, moves, sort));
	if (stacks->b_amount > 1 && stacks->a_amount > 1)
		return (ps_brute_force_state_3(stacks, moves, sort));
	if (stacks->a_amount == 1 && stacks->b_amount > 0)
		return (ps_brute_force_state_4(stacks, moves, sort));
	if (stacks->a_amount == 0 && stacks->b_amount > 0)
		return (ps_brute_force_state_5(stacks, moves, sort));
	return (-1);
}

int		ps_brute_force_decision_force(t_stacks *stacks, t_keychain *moves,
		int layer, t_direction_sort *sort)
{
	if (layer == 0)
		return (ps_brute_force_decision_top(stacks, moves, sort));
	if (stacks->b_amount == 0 && stacks->a_amount > 0)
		return (ps_brute_force_state_1_force(stacks, moves, layer, sort));
	if (stacks->b_amount == 1 && stacks->a_amount > 0)
		return (ps_brute_force_state_2_force(stacks, moves, layer, sort));
	if (stacks->b_amount > 1 && stacks->a_amount > 1)
		return (ps_brute_force_state_3_force(stacks, moves, layer, sort));
	if (stacks->a_amount == 1 && stacks->b_amount > 0)
		return (ps_brute_force_state_4_force(stacks, moves, layer, sort));
	if (stacks->a_amount == 0 && stacks->b_amount > 0)
		return (ps_brute_force_state_5_force(stacks, moves, layer, sort));
	return (-1);
}

int		ps_brute_force_descision(t_stacks *stacks, t_keychain *moves, int layer,
	t_direction_sort *sort)
{
	int ret;

	ret = 0;
	if (layer == 0)
		return (ps_brute_force_decision_top(stacks, moves, sort));
	else
		return (ps_brute_force_decision_force(stacks, moves, layer, sort));
}

void	ps_brute_force(t_stacks *stacks, t_keychain *moves,
		t_direction_sort *sort)
{
	int	state;
	int layer;

	layer = 0;
	state = 1;
	if (sort->sort(sort->stack, *sort->stack_amount) == 1)
		return ;
	while (state == 1)
	{
		state = ps_brute_force_descision(stacks, moves, layer, sort);
		layer++;
	}
}
