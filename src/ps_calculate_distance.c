/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_calculate_distance.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/15 11:44:19 by mlokhors       #+#    #+#                */
/*   Updated: 2019/12/18 20:28:40 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ps_check_for_target(t_numbers **runner_1, t_numbers *runner_2,
				t_info *info)
{
	if (((runner_2)->number == *(info->init_min) &&
		(runner_2)->prev->number == *(info->init_max) &&
		((*runner_1)->number > *(info->init_max) ||
		(*runner_1)->number < (*info->init_min))) ||
		(((*runner_1)->number < (runner_2)->number &&
		(*runner_1)->number > (runner_2)->prev->number)))
		return (1);
	return (0);
}

static int		ps_check_for_target_rev(t_numbers **runner_1,
				t_numbers *runner_2, t_info *info)
{
	if (((runner_2)->number == *info->init_max &&
		(runner_2)->prev->number == *info->init_min &&
		((*runner_1)->number > *info->init_max ||
		(*runner_1)->number < *info->init_min)) ||
		((*runner_1)->number > (runner_2)->number &&
		(*runner_1)->number < (runner_2)->prev->number))
		return (1);
	return (0);
}

void			ps_search_fit_inside(t_numbers **runner_1, t_numbers *runner_2,
				t_info *info, int from_start)
{
	int i;

	i = 0;
	while (i < *(info->amount_2))
	{
		if (info->order == REV_ORDER)
		{
			if (ps_check_for_target_rev(runner_1, runner_2, info) == 1)
			{
				set_target_1(runner_1, runner_2, *(info->amount_1), from_start);
				break ;
			}
		}
		else
		{
			if (ps_check_for_target(runner_1, runner_2, info) == 1)
			{
				set_target_1(runner_1, runner_2, *(info->amount_1), from_start);
				break ;
			}
		}
		runner_2 = runner_2->next;
		i++;
	}
}

void			ps_calculate_distance(t_info *info)
{
	int			i;
	t_numbers	*runner_1;
	t_numbers	*runner_2;

	i = 0;
	runner_1 = *(info->stack_1);
	ps_set_small_stack_targets(info->stack_2, *(info->amount_2));
	while (runner_1 && i < *(info->amount_1))
	{
		runner_2 = *(info->stack_2);
		ps_search_fit_inside(&runner_1, runner_2, info, i);
		runner_1 = runner_1->next;
		i++;
	}
}
