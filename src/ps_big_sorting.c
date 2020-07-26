/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_big_sorting.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/14 04:23:26 by mlokhors       #+#    #+#                */
/*   Updated: 2019/12/18 20:04:01 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			ps_bs_b_push(t_stacks *stacks, t_keychain *moves, int limit)
{
	int i;

	i = 0;
	while (i < limit)
	{
		ps_add_instruction_and_operations(stacks, moves, E_PB);
		i++;
	}
}

static int			ps_set_limit(int a_amount)
{
	if (a_amount < 15)
		return (3);
	else
		return (4);
}

static void			ps_set_info(t_info *info, t_stacks *stacks)
{
	if (stacks->a_amount > stacks->b_amount)
	{
		info->amount_1 = &stacks->a_amount;
		info->amount_2 = &stacks->b_amount;
		info->stack_1 = &stacks->a;
		info->stack_2 = &stacks->b;
		info->init_max = &stacks->b->number;
		info->init_min = &stacks->b->prev->number;
		info->order = REV_ORDER;
	}
	else
	{
		info->amount_1 = &stacks->b_amount;
		info->amount_2 = &stacks->a_amount;
		info->stack_1 = &stacks->b;
		info->stack_2 = &stacks->a;
		info->init_max = &stacks->a->prev->number;
		info->init_min = &stacks->a->number;
		info->order = ORDER;
	}
}

static void			ps_check_for_new_max_min(t_info *info, t_stacks *stacks)
{
	if (info->order == ORDER)
	{
		if (*(info)->init_max < stacks->a->number)
			info->init_max = &stacks->a->number;
		if (*(info)->init_min > stacks->a->number)
			info->init_min = &stacks->a->number;
	}
	else
	{
		if (*(info)->init_max < stacks->b->number)
			info->init_max = &stacks->b->number;
		if (*(info)->init_min > stacks->b->number)
			info->init_min = &stacks->b->number;
	}
}

void				ps_big_sorting(t_stacks *stacks, t_keychain *moves,
					t_direction_sort *sort)
{
	int		limit;
	t_info	info;

	limit = ps_set_limit(stacks->a_amount);
	ps_bs_b_push(stacks, moves, limit);
	ps_set_sort_stack_to_rev(stacks, sort, limit);
	ps_brute_force(stacks, moves, sort);
	ps_set_info(&info, stacks);
	while (stacks->a_amount > limit)
	{
		ps_check_for_new_max_min(&info, stacks);
		ps_calculate_distance(&info);
		ps_search_and_do_shortest_distance(&info, stacks, moves);
	}
	ps_set_sort_stack_to_in_order(stacks, sort, limit);
	ps_brute_force(stacks, moves, sort);
	ps_set_info(&info, stacks);
	while (stacks->b_amount > 0)
	{
		ps_check_for_new_max_min(&info, stacks);
		ps_calculate_distance(&info);
		ps_search_and_do_shortest_distance(&info, stacks, moves);
	}
	ps_shift_stack(stacks, moves);
}
