/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_add_instruction_and_operations.c                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 04:58:42 by mlokhors       #+#    #+#                */
/*   Updated: 2019/12/18 19:49:54 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ps_add_new_key_node_to_list(t_keychain *keys, t_key *new,
				int len)
{
	t_key	*runner;
	int		i;

	i = 0;
	runner = keys->instructions;
	while (i < len)
	{
		runner = runner->next;
		i++;
	}
	new->next = keys->instructions;
	new->prev = runner;
	runner->next = new;
	keys->instructions->prev = new;
	keys->list_count++;
}

static t_key	*ps_new_key_node(t_stacks *stacks, t_keychain *instructions,
				const char *operation)
{
	t_key		*new;

	new = (t_key *)malloc(sizeof(t_key));
	if (!new)
		ps_error_with_list(stacks, instructions);
	new->moves = ft_strdup(operation);
	if (!new->moves)
		ps_error_with_list(stacks, instructions);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

static void		ps_add_instruction(t_stacks *stacks, t_keychain *instructions,
				int operation)
{
	int			i;
	t_key		*new;
	const char	*moves[11] = {"sa\n", "sb\n", "ss\n", "pb\n", "pa\n",
							"ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"
	};

	new = ps_new_key_node(stacks, instructions, moves[operation]);
	i = 0;
	if (instructions->list_count == 0)
	{
		new->next = new;
		new->prev = new;
		instructions->instructions = new;
		instructions->list_count++;
	}
	else
		ps_add_new_key_node_to_list(instructions, new,
		(instructions->list_count - 1));
}

void			ps_add_instruction_and_operations(t_stacks *stacks,
			t_keychain *instructions, int operation)
{
	ps_add_instruction(stacks, instructions, operation);
	sh_do_instruction(stacks, operation);
}
