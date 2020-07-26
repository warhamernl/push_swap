/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sh_natoi.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/07 13:11:36 by mlokhors       #+#    #+#                */
/*   Updated: 2019/12/18 19:34:58 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long			sh_natoi(char **str)
{
	int		nega;
	long	result;

	nega = 1;
	result = 0;
	while (ft_isspace((int)**str) == 1)
		(*str)++;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			nega = -1;
		(*str)++;
	}
	while (**str >= '0' && **str <= '9')
	{
		result = result * 10 + **str - '0';
		(*str)++;
	}
	return ((long)nega * result);
}
