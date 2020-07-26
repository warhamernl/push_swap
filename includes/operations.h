/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 11:39:48 by mlokhors       #+#    #+#                */
/*   Updated: 2019/12/18 19:46:56 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H
# include "push_swap.h"

void			sh_sa(t_stacks *stacks);
void			sh_sb(t_stacks *stacks);
void			sh_ss(t_stacks *stacks);
void			sh_pb(t_stacks *stacks);
void			sh_pa(t_stacks *stacks);
void			sh_ra(t_stacks *stacks);
void			sh_rb(t_stacks *stacks);
void			sh_rr(t_stacks *stacks);
void			sh_rra(t_stacks *stacks);
void			sh_rrb(t_stacks *stacks);
void			sh_rrr(t_stacks *stacks);
typedef void	(*t_operation)(t_stacks *stacks);

#endif
