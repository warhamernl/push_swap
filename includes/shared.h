/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shared.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/03 14:37:41 by mlokhors       #+#    #+#                */
/*   Updated: 2019/12/18 20:26:40 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H
# include <stdlib.h>
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"
# include <fcntl.h>

typedef	struct			s_key
{
	char				*moves;
	struct s_key		*prev;
	struct s_key		*next;
}						t_key;

typedef struct			s_numbers
{
	int					number;
	int					steps;
	int					direction;
	int					steps_total;
	struct s_numbers	*prev;
	struct s_numbers	*next;
	struct s_numbers	*target;
}						t_numbers;

typedef struct			s_stacks
{
	t_numbers			*a;
	t_numbers			*b;
	int					a_amount;
	int					a_max;
	int					a_min;
	int					b_amount;
	int					b_max;
	int					b_min;
}						t_stacks;

void					sh_free_stack(t_numbers *stack, int amount);
int						sh_is_sorted(t_numbers **stack, int stack_amount);
int						sh_check_and_add_elem(t_stacks *stacks,
						t_numbers **runner, char **str, int diff_argc);
void					sh_do_instruction(t_stacks *stacks, int operation);
long					sh_natoi(char **str);
t_numbers				*sh_new_elem(t_stacks *stacks);
void					sh_error_only_stack(t_stacks *stacks);
void					sh_check_stack(t_stacks *stacks, char **str, int argc);
void					sh_init_stacks(t_stacks *stacks);

#endif
