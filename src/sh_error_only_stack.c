/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sh_error_only_stack.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 11:27:33 by mlokhors       #+#    #+#                */
/*   Updated: 2019/12/18 20:05:05 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void			sh_free_stack(t_numbers *stack, int amount)
{
	t_numbers *tmp;

	tmp = NULL;
	if (stack && stack->next)
	{
		if (stack->prev)
			stack->prev->next = NULL;
		while (amount != 0 && stack)
		{
			tmp = stack;
			stack = stack->next;
			free(tmp);
			amount--;
		}
	}
	else
	{
		if (stack)
			free(stack);
	}
}

void			sh_error_only_stack(t_stacks *stacks)
{
	if (stacks->a)
		sh_free_stack(stacks->a, stacks->a_amount);
	if (stacks->b)
		sh_free_stack(stacks->b, stacks->b_amount);
	ft_printf("Error\n");
	exit(-1);
}
