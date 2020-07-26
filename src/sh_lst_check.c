/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sh_lst_check.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/14 01:39:21 by mlokhors       #+#    #+#                */
/*   Updated: 2019/12/18 20:08:51 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		sh_check_size(t_stacks *stacks,
				t_numbers *runner, long long number)
{
	if (number > INT_MAX || number < INT_MIN)
		return (-1);
	runner->number = (int)number;
	if (stacks->a_amount == 0)
	{
		stacks->a_max = number;
		stacks->a_min = number;
	}
	else
	{
		if (number < stacks->a_min)
			stacks->a_min = number;
		if (number > stacks->a_max)
			stacks->a_max = number;
	}
	stacks->a_amount++;
	return (0);
}

static int		sh_check_input(char **str)
{
	while (ft_isspace((int)**str == 0))
		(*str)++;
	if (ft_isspace((int)**str) == 0 && !(**str == '+'
		|| **str == '-' || **str == '\0') &&
		!(**str >= '0' && **str <= '9'))
		return (-1);
	if (**str == '\0')
		return (1);
	return (0);
}

int				sh_check_and_add_elem(t_stacks *stacks,
				t_numbers **runner, char **str, int diff_argc)
{
	long long	number;
	int			check;

	number = 0;
	while (**str)
	{
		check = sh_check_input(str);
		if (check == 1 || check == -1)
			return (check);
		number = sh_natoi(str);
		if (sh_check_size(stacks, *runner, number) == -1)
			return (-1);
		check = sh_check_input(str);
		if (diff_argc == 1 && check == 1)
			return (0);
		(*runner)->next = sh_new_elem(stacks);
		if ((*runner)->next == NULL)
			return (-1);
		(*runner)->next->prev = (*runner);
		(*runner) = (*runner)->next;
	}
	return (0);
}
