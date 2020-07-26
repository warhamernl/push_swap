/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_undo_instructions.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 18:28:59 by mlokhors       #+#    #+#                */
/*   Updated: 2019/12/18 20:15:03 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operations.h"

static void		ps_undo_operation(t_stacks *stacks, int operation)
{
	const t_operation operation_list[11] = {
	sh_sa, sh_sb, sh_ss, sh_pa, sh_pb, sh_rra,
	sh_rrb, sh_rrr, sh_ra, sh_rb, sh_rr
	};

	operation_list[operation](stacks);
}

static	void	ps_del_node(t_key *del)
{
	del->next = NULL;
	del->prev = NULL;
	free(del->moves);
	del->moves = NULL;
	free(del);
	del = NULL;
}

static void		ps_undo_instructions(t_keychain *moves)
{
	t_key	*prev;
	t_key	*remove;

	prev = NULL;
	remove = NULL;
	if (moves->list_count == 1)
	{
		moves->list_count--;
		ps_del_node(moves->instructions);
	}
	else
	{
		prev = moves->instructions->prev->prev;
		remove = moves->instructions->prev;
		prev->next = moves->instructions;
		moves->instructions->prev = prev;
		ps_del_node(remove);
		moves->list_count--;
	}
}

void			ps_release_last_instruction(t_stacks *stacks, t_keychain *moves,
			int operation)
{
	ps_undo_operation(stacks, operation);
	ps_undo_instructions(moves);
}
