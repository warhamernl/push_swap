/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_set_sort_stack.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 14:49:39 by mlokhors       #+#    #+#                */
/*   Updated: 2019/12/18 20:23:25 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ps_set_sort_stack_to_in_order(t_stacks *stacks,
					t_direction_sort *sort, int limit)
{
	sort->stack = NULL;
	sort->end_amount = limit;
	sort->sort = &sh_is_sorted;
	sort->stack = &stacks->a;
	sort->stack_amount = &stacks->a_amount;
}

void			ps_set_sort_stack_to_rev(t_stacks *stacks,
					t_direction_sort *sort, int limit)
{
	sort->stack = NULL;
	sort->end_amount = limit;
	sort->sort = &ps_is_rev_sorted;
	sort->stack = &stacks->b;
	sort->stack_amount = &stacks->b_amount;
}
