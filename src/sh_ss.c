/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sh_ss.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 02:21:57 by mlokhors       #+#    #+#                */
/*   Updated: 2019/12/18 19:48:29 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sh_sa(t_stacks *stacks)
{
	t_numbers	*tmp;
	t_numbers	*p_tmp;

	tmp = NULL;
	p_tmp = NULL;
	if (stacks->a_amount > 1)
	{
		tmp = stacks->a;
		p_tmp = stacks->a->prev;
		stacks->a = stacks->a->next;
		stacks->a->prev = p_tmp;
		p_tmp->next = stacks->a;
		tmp->next = stacks->a->next;
		stacks->a->next->prev = tmp;
		stacks->a->next = tmp;
		tmp->prev = stacks->a;
	}
}

void		sh_sb(t_stacks *stacks)
{
	t_numbers	*tmp;
	t_numbers	*p_tmp;

	tmp = NULL;
	p_tmp = NULL;
	if (stacks->b_amount > 1)
	{
		tmp = stacks->b;
		p_tmp = stacks->b->prev;
		stacks->b = stacks->b->next;
		stacks->b->prev = p_tmp;
		p_tmp->next = stacks->b;
		tmp->next = stacks->b->next;
		stacks->b->next->prev = tmp;
		stacks->b->next = tmp;
		tmp->prev = stacks->b;
	}
	return ;
}

void		sh_ss(t_stacks *stacks)
{
	sh_sa(stacks);
	sh_sb(stacks);
}
