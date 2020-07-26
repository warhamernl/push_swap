/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sh_check_stack.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 11:18:38 by mlokhors       #+#    #+#                */
/*   Updated: 2019/12/18 20:03:39 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		sh_check_dub(t_stacks *stacks, int amount)
{
	int			i;
	int			j;
	t_numbers	*tmp;
	t_numbers	*runner;

	i = 0;
	runner = stacks->a;
	while (runner && i < (amount - 1))
	{
		j = i + 1;
		tmp = runner->next;
		while (tmp && j < amount)
		{
			if (tmp->number == runner->number)
				sh_error_only_stack(stacks);
			if (tmp->next == NULL)
				break ;
			tmp = tmp->next;
			j++;
		}
		i++;
		runner = runner->next;
	}
}

static void		sh_get_list(t_stacks *stacks, char **str, int argc)
{
	int			i;
	t_numbers	*runner;
	t_numbers	*start;

	i = 0;
	stacks->a = sh_new_elem(stacks);
	runner = stacks->a;
	start = stacks->a;
	while (i < (argc))
	{
		while (*str)
		{
			if (sh_check_and_add_elem(stacks, &runner, str, (argc - i)) == -1)
				sh_error_only_stack(stacks);
			if (**str == '\0')
				break ;
			str++;
		}
		(*str)++;
		i++;
	}
	runner->next = stacks->a;
	stacks->a->prev = runner;
}

void			sh_check_stack(t_stacks *stacks, char **str, int argc)
{
	sh_get_list(stacks, str, argc);
	sh_check_dub(stacks, stacks->a_amount);
}
