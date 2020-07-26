/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ch_checker.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/07 16:41:11 by mlokhors       #+#    #+#                */
/*   Updated: 2019/12/19 15:24:51 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ch_end_free(t_stacks *stacks)
{
	if (stacks->a)
		sh_free_stack(stacks->a, stacks->a_amount);
	if (stacks->b)
		sh_free_stack(stacks->b, stacks->b_amount);
}

static int		ch_checker_cmp_do_instructions(t_stacks *stacks, char *str)
{
	int			i;
	const char	*instructions[11] = {"sa", "sb", "ss", "pb", "pa",
	"ra", "rb", "rr", "rra", "rrb", "rrr" };

	i = 0;
	while (i < 11)
	{
		if (ft_strcmp(str, instructions[i]) == 0)
		{
			sh_do_instruction(stacks, i);
			return (0);
		}
		i++;
	}
	if (i == 11)
		return (-1);
	return (0);
}

static int		ch_checker_read_instructions(t_stacks *stack)
{
	char			*str;
	int				ret;

	ret = 1;
	str = NULL;
	while (ret == 1)
	{
		ret = ft_get_next_line(0, &str);
		if (ret < 1 || ft_strlen(str) == 0 || !str)
			return (0);
		if (ch_checker_cmp_do_instructions(stack, str) == -1)
			return (-1);
		ft_strdel(&str);
	}
	return (-1);
}

static void		ch_checker_sort(t_stacks *stacks)
{
	if (ch_checker_read_instructions(stacks) == -1)
	{
		ft_printf("Error\n");
		return ;
	}
	if (sh_is_sorted(&stacks->a, stacks->a_amount) && stacks->b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int				main(int argc, char **argv)
{
	t_stacks	stacks;

	sh_init_stacks(&stacks);
	if (argc >= 2)
	{
		argv++;
		sh_check_stack(&stacks, argv, (argc - 1));
		ch_checker_sort(&stacks);
		ch_end_free(&stacks);
	}
	return (0);
}
