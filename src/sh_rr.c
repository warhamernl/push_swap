/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sh_rr.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 02:16:39 by mlokhors       #+#    #+#                */
/*   Updated: 2019/12/18 19:45:19 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sh_ra(t_stacks *stacks)
{
	if (stacks->a != NULL)
		stacks->a = stacks->a->next;
}

void		sh_rb(t_stacks *stacks)
{
	if (stacks->b != NULL)
		stacks->b = stacks->b->next;
}

void		sh_rr(t_stacks *stacks)
{
	sh_ra(stacks);
	sh_rb(stacks);
}
