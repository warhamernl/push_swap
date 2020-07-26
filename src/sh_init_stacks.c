/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sh_init_stacks.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 08:49:01 by mlokhors       #+#    #+#                */
/*   Updated: 2019/12/18 19:42:08 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void				sh_init_stacks(t_stacks *stacks)
{
	stacks->a = NULL;
	stacks->a_amount = 0;
	stacks->a_max = 0;
	stacks->a_min = 0;
	stacks->b = NULL;
	stacks->b_amount = 0;
	stacks->b_amount = 0;
	stacks->b_max = 0;
	stacks->b_min = 0;
}
