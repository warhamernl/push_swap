/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_set_target_1.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 14:28:38 by mlokhors       #+#    #+#                */
/*   Updated: 2019/12/18 20:13:22 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ps_set_total(t_numbers **runner_1, t_numbers *runner_2)
{
	t_numbers *total;

	total = *runner_1;
	if (((total->direction == UP || total->direction == UPDOWN) &&
		(runner_2->direction == UP || runner_2->direction == UPDOWN)) ||
		((total->direction == DOWN || total->direction == UPDOWN) &&
		(runner_2->direction == DOWN || runner_2->direction == UPDOWN)))
	{
		if (total->steps > runner_2->steps)
			total->steps_total = total->steps;
		else
			total->steps_total = runner_2->steps;
	}
	else
		total->steps_total = runner_2->steps + total->steps;
}

static void		ps_set_target_up(t_numbers **target, t_numbers *runner,
				int from_start)
{
	(*target)->steps = from_start;
	(*target)->direction = UP;
	(*target)->target = runner;
}

static void		ps_set_target_down(t_numbers **target, t_numbers *runner,
				int amount, int from_start)
{
	(*target)->steps = amount - from_start;
	(*target)->direction = DOWN;
	(*target)->target = runner;
}

void			set_target_1(t_numbers **runner_1, t_numbers *runner_2,
				int amount, int from_start)
{
	int			divided;
	t_numbers	*target;

	target = *runner_1;
	if (amount % 2 == 1)
		divided = amount / 2 + 1;
	else
		divided = amount / 2;
	if (from_start > divided)
		ps_set_target_down(&target, runner_2, amount, from_start);
	else if (from_start != 0)
		ps_set_target_up(&target, runner_2, from_start);
	else
	{
		if (amount - from_start == amount)
			target->steps = 0;
		else
			target->steps = amount - from_start;
		target->direction = UPDOWN;
		target->target = runner_2;
	}
	ps_set_total(runner_1, runner_2);
}
