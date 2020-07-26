/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sh_rrr.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 02:18:19 by mlokhors       #+#    #+#                */
/*   Updated: 2019/12/19 15:25:46 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sh_rra(t_stacks *stacks)
{
	if (stacks->a != NULL)
		stacks->a = stacks->a->prev;
}

void		sh_rrb(t_stacks *stacks)
{
	if (stacks->b != NULL)
		stacks->b = stacks->b->prev;
}

void		sh_rrr(t_stacks *stacks)
{
	sh_rra(stacks);
	sh_rrb(stacks);
}
