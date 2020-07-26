/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_excute_up_down.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 14:41:46 by mlokhors       #+#    #+#                */
/*   Updated: 2019/12/18 20:06:48 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ps_do_single_rotations(t_stacks *stacks, t_keychain *moves,
				t_numbers *runner, t_side_function_pointer *functions)
{
	while (functions->i < runner->steps)
	{
		ps_add_instruction_and_operations(stacks, moves,
		functions->rotate_single);
		functions->i++;
	}
	if (runner->target != NULL)
	{
		while (functions->i < runner->steps_total)
		{
			ps_add_instruction_and_operations(stacks, moves,
			functions->rotate_rev_single);
			functions->i++;
		}
	}
}

void			ps_do_double_rotations(t_stacks *stacks, t_keychain *moves,
				t_numbers *runner, t_side_function_pointer *functions)
{
	while (runner->target != NULL &&
	functions->i < runner->target->steps &&
	functions->i < runner->steps &&
	(runner->target->direction == runner->direction ||
	runner->target->direction == UPDOWN ||
	runner->direction == UPDOWN))
	{
		ps_add_instruction_and_operations(stacks, moves,
		functions->rotate_double);
		functions->i++;
	}
}

void			ps_excute_up_or_down(t_stacks *stacks, t_keychain *moves,
				t_numbers *runner, t_info *info)
{
	t_side_function_pointer functions;

	ps_init_up_functions(&functions, runner, info->order);
	ps_do_double_rotations(stacks, moves, runner, &functions);
	ps_do_single_rotations(stacks, moves, runner, &functions);
	ps_add_instruction_and_operations(stacks, moves, functions.push);
}
