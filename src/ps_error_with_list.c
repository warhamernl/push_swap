/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_error_with_list.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 09:28:39 by mlokhors       #+#    #+#                */
/*   Updated: 2019/12/19 13:11:59 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ps_free_operation(t_key *move, int amount)
{
	t_key *tmp;

	tmp = NULL;
	if (move && move->next)
	{
		move->prev->next = NULL;
		while (amount != 0 && move)
		{
			tmp = move;
			move = move->next;
			free(tmp->moves);
			free(tmp);
			amount--;
		}
	}
	else
	{
		if (move)
		{
			free(move->moves);
			free(move);
		}
	}
}

void		ps_error_with_list(t_stacks *stacks, t_keychain *moves)
{
	if (stacks->a)
		sh_free_stack(stacks->a, stacks->a_amount);
	if (stacks->b)
		sh_free_stack(stacks->b, stacks->b_amount);
	if (moves->instructions)
		ps_free_operation(moves->instructions, moves->list_count);
	ft_printf("Error\n");
	exit(-1);
}
