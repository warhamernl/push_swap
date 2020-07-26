/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_push_swap.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 20:15:53 by mlokhors       #+#    #+#                */
/*   Updated: 2019/12/18 20:24:38 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void				ps_print_instruction(t_keychain *moves)
{
	t_key	*list_of_keys;
	int		i;

	i = 0;
	list_of_keys = moves->instructions;
	while (i < moves->list_count)
	{
		ft_printf("%s", list_of_keys->moves);
		list_of_keys = list_of_keys->next;
		i++;
	}
}

static void				ps_end_free(t_stacks *stacks, t_keychain *moves)
{
	if (stacks->a)
		sh_free_stack(stacks->a, stacks->a_amount);
	if (stacks->b)
		sh_free_stack(stacks->b, stacks->b_amount);
	if (moves->instructions)
		ps_free_operation(moves->instructions, moves->list_count);
}

static void				ps_init_instruction(t_keychain *moves)
{
	moves->list_count = 0;
	moves->instructions = NULL;
}

static void				ps_sorting(t_stacks *stacks, t_keychain *moves)
{
	t_direction_sort sort;

	sort.end_amount = stacks->a_amount;
	sort.sort = &sh_is_sorted;
	sort.stack_amount = &stacks->a_amount;
	sort.stack = &stacks->a;
	if (sort.sort(sort.stack, *sort.stack_amount) == 1)
		return ;
	if (stacks->a_amount <= 5)
		ps_brute_force(stacks, moves, &sort);
	else
		ps_big_sorting(stacks, moves, &sort);
}

int						main(int argc, char **argv)
{
	t_stacks			stacks;
	t_keychain			moves;

	ps_init_instruction(&moves);
	sh_init_stacks(&stacks);
	if (argc >= 2)
	{
		argv++;
		sh_check_stack(&stacks, argv, (argc - 1));
		ps_sorting(&stacks, &moves);
		ps_print_instruction(&moves);
		ps_end_free(&stacks, &moves);
	}
	return (0);
}
