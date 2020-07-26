/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_set_target_2.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 14:29:56 by mlokhors       #+#    #+#                */
/*   Updated: 2019/12/18 20:29:08 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ps_set_target_2(t_numbers **runner,
				int i, int divided, int amount)
{
	t_numbers *target;

	target = *runner;
	target->steps = 0;
	target->direction = 0;
	if (amount - i == i || i == 0)
	{
		target->steps = i;
		target->direction = UPDOWN;
	}
	else if (i > divided)
	{
		target->steps = (amount - divided) - (i - divided);
		target->direction = DOWN;
	}
	else
	{
		target->steps = i;
		target->direction = UP;
	}
	target->target = NULL;
	target->steps_total = -1;
}

void			ps_set_small_stack_targets(t_numbers **stack, int amount)
{
	int			i;
	int			divided;
	t_numbers	*runner;

	i = 0;
	divided = amount / 2;
	runner = *stack;
	while (runner && i < amount)
	{
		ps_set_target_2(&runner, i, divided, amount);
		runner = runner->next;
		i++;
	}
}
