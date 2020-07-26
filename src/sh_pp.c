/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sh_pp.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 02:22:11 by mlokhors       #+#    #+#                */
/*   Updated: 2019/12/18 19:45:43 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sh_push(t_numbers **stack, t_numbers *tmp, int amount)
{
	if ((*stack) == NULL && amount == 0)
	{
		(*stack) = tmp;
		(*stack)->prev = tmp;
		(*stack)->next = tmp;
	}
	else if (amount > 0)
	{
		(*stack)->prev->next = tmp;
		tmp->next = (*stack);
		tmp->prev = (*stack)->prev;
		(*stack)->prev = tmp;
		(*stack) = tmp;
	}
}

void		sh_pb(t_stacks *stacks)
{
	t_numbers *tmp;
	t_numbers *prev;

	if (stacks->a != NULL)
	{
		tmp = stacks->a;
		prev = stacks->a->prev;
		stacks->a = stacks->a->next;
		prev->next = stacks->a;
		stacks->a->prev = prev;
		sh_push(&stacks->b, tmp, stacks->b_amount);
		if (stacks->a_amount == 1)
			stacks->a = NULL;
		stacks->a_amount--;
		stacks->b_amount++;
	}
}

void		sh_pa(t_stacks *stacks)
{
	t_numbers *tmp;
	t_numbers *prev;

	if (stacks->b != NULL)
	{
		tmp = stacks->b;
		prev = stacks->b->prev;
		stacks->b = stacks->b->next;
		prev->next = stacks->b;
		stacks->b->prev = prev;
		sh_push(&stacks->a, tmp, stacks->a_amount);
		if (stacks->b_amount == 1)
			stacks->b = NULL;
		stacks->b_amount--;
		stacks->a_amount++;
	}
}
