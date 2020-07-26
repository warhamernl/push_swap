/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_init_functions.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 13:22:24 by mlokhors       #+#    #+#                */
/*   Updated: 2019/12/18 20:07:28 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ps_rotate_rev_function_a(t_side_function_pointer **functions,
				t_numbers *runner)
{
	if (runner->target->direction == UP)
		(*functions)->rotate_rev_single = E_RA;
	else
		(*functions)->rotate_rev_single = E_RRA;
}

static void		ps_rotate_rev_function_b(t_side_function_pointer **functions,
				t_numbers *runner)
{
	if (runner->target->direction == UP)
		(*functions)->rotate_rev_single = E_RB;
	else
		(*functions)->rotate_rev_single = E_RRB;
}

static void		ps_init_up_functions2(t_side_function_pointer *functions,
				t_numbers *runner)
{
	if (runner->direction == UP)
	{
		ps_rotate_rev_function_a(&functions, runner);
		functions->rotate_double = E_RR;
		functions->rotate_single = E_RB;
		functions->push = E_PA;
	}
	else
	{
		ps_rotate_rev_function_a(&functions, runner);
		functions->rotate_double = E_RRR;
		functions->rotate_single = E_RRB;
		functions->push = E_PA;
	}
}

void			ps_init_up_functions(t_side_function_pointer *functions,
				t_numbers *runner, int which_stack)
{
	functions->i = 0;
	if (which_stack == 1)
	{
		if (runner->direction == UP)
		{
			ps_rotate_rev_function_b(&functions, runner);
			functions->rotate_double = E_RR;
			functions->rotate_single = E_RA;
			functions->push = E_PB;
		}
		else
		{
			ps_rotate_rev_function_b(&functions, runner);
			functions->rotate_double = E_RRR;
			functions->rotate_single = E_RRA;
			functions->push = E_PB;
		}
	}
	else
		ps_init_up_functions2(functions, runner);
}
