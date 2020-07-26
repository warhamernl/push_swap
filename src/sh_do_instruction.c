/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sh_do_instruction.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 03:59:51 by mlokhors       #+#    #+#                */
/*   Updated: 2019/12/18 19:47:50 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "operations.h"

void		sh_do_instruction(t_stacks *stacks, int operation)
{
	const t_operation operation_list[11] = {
	sh_sa, sh_sb, sh_ss, sh_pb, sh_pa, sh_ra, sh_rb,
	sh_rr, sh_rra, sh_rrb, sh_rrr };

	operation_list[operation](stacks);
}
