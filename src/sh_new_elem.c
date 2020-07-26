/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sh_new_elem.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 23:41:52 by mlokhors       #+#    #+#                */
/*   Updated: 2019/12/18 20:09:30 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_numbers	*sh_new_elem(t_stacks *stacks)
{
	t_numbers *new;

	new = NULL;
	new = (t_numbers *)malloc(sizeof(t_numbers));
	if (!new)
		sh_error_only_stack(stacks);
	new->number = 0;
	new->steps = 0;
	new->direction = 0;
	new->steps_total = -1;
	new->target = NULL;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
