/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_is_rev_sorted.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 03:05:06 by mlokhors       #+#    #+#                */
/*   Updated: 2019/12/18 17:32:31 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_is_rev_sorted(t_numbers **stack, int stack_amount)
{
	t_numbers	*runner;
	int			i;

	i = 0;
	runner = *stack;
	if (stack_amount == 1)
		return (1);
	if (!*stack)
		return (-1);
	while (runner && i < stack_amount)
	{
		if (runner->next && runner->number < runner->next->number)
			break ;
		i++;
		runner = runner->next;
	}
	if (runner->next == *stack)
		i++;
	if (i == stack_amount)
		return (1);
	return (0);
}
