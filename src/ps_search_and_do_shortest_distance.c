/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_search_and_do_shortest_distance.c               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/15 11:48:55 by mlokhors       #+#    #+#                */
/*   Updated: 2019/12/18 20:12:40 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ps_reverse_node_target_node(t_distance *distance,
				t_numbers **runner_down, t_numbers **runner_up)
{
	if (distance->type_runner == 0)
	{
		while (*runner_down != distance->rev_node)
			(*runner_down) = (*runner_down)->prev;
	}
	else
	{
		while (*runner_up != distance->rev_node)
			(*runner_up) = (*runner_up)->next;
	}
}

void			ps_init_distance(t_distance *distance)
{
	distance->i = 0;
	distance->save_i = -1;
	distance->path = -1;
	distance->rev_node = NULL;
	distance->type_runner = -1;
}

int				ps_set_amount(t_info *info)
{
	if (*(info->amount_1) == 1)
		return (1);
	if (*(info->amount_1) / 2 == 1)
		return (*(info->amount_1) / 2 + 1);
	return (*(info->amount_1) / 2);
}

void			ps_search_and_do_shortest_distance(t_info *info,
				t_stacks *stacks, t_keychain *moves)
{
	int			amount;
	t_numbers	*runner_down;
	t_numbers	*runner_up;
	t_distance	distance;

	runner_down = *(info->stack_1);
	runner_up = *(info->stack_1);
	ps_init_distance(&distance);
	amount = ps_set_amount(info);
	while (distance.i < amount &&
		(distance.path > distance.i || distance.path == -1))
	{
		ps_search_for_lowest_distance(&distance, runner_down, runner_up, info);
		runner_down = runner_down->next;
		runner_up = runner_up->prev;
		distance.i++;
	}
	ps_reverse_node_target_node(&distance, &runner_down, &runner_up);
	if (distance.type_runner == DOWN)
		ps_excute_up_or_down(stacks, moves, distance.rev_node, info);
	else
		ps_excute_up_or_down(stacks, moves, distance.rev_node, info);
}
