/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_shift_stack.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 12:04:34 by mlokhors       #+#    #+#                */
/*   Updated: 2019/12/18 20:13:43 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ps_shift_direction(t_stacks *stacks, t_keychain *moves,
				int amount, int direction)
{
	int i;

	i = 0;
	while (i < amount)
	{
		ps_add_instruction_and_operations(stacks, moves, direction);
		i++;
	}
}

void			ps_shift_stack(t_stacks *stacks, t_keychain *moves)
{
	int			min;
	int			i;
	int			save_i;
	t_numbers	*runner;

	min = 0;
	i = 0;
	save_i = 0;
	runner = stacks->a;
	while (runner && i < stacks->a_amount)
	{
		if (i == 0 || runner->number < min)
		{
			min = runner->number;
			save_i = i;
		}
		i++;
		runner = runner->next;
	}
	if (save_i > (stacks->a_amount - save_i))
		ps_shift_direction(stacks, moves, (stacks->a_amount - save_i), E_RRA);
	else
		ps_shift_direction(stacks, moves, save_i, E_RA);
}
