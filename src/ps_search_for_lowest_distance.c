/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_search_for_lowest_distance.c                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 14:43:13 by mlokhors       #+#    #+#                */
/*   Updated: 2019/12/18 20:33:21 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ps_fill_in_distance(t_distance *distance, t_numbers *runner)
{
	if (runner->direction == UPDOWN)
		distance->type_runner = runner->target->direction;
	else
		distance->type_runner = runner->direction;
	distance->rev_node = runner;
	distance->save_i = distance->i;
	distance->path = runner->steps_total;
}

void			ps_search_for_lowest_distance(t_distance *distance,
				t_numbers *runner_down, t_numbers *runner_up, t_info *info)
{
	int amount;

	amount = *(info->amount_1);
	if ((runner_down == runner_up && distance->path > runner_down->steps_total)
	|| distance->path == -1)
		ps_fill_in_distance(distance, runner_down);
	else if ((distance->path > runner_down->steps_total))
		ps_fill_in_distance(distance, runner_down);
	else if ((distance->path > runner_up->steps_total) || distance->path == -1)
		ps_fill_in_distance(distance, runner_up);
}
