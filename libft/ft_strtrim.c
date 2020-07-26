/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 18:22:42 by mlokhors       #+#    #+#                */
/*   Updated: 2019/08/10 22:58:37 by mark          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	size_t	begin;
	size_t	end;
	char	*trimmed;

	if (!s)
		return (NULL);
	end = ft_strlen(s);
	begin = 0;
	while (s[begin] == ' ' || s[begin] == '\n' || s[begin] == '\t')
		begin++;
	if (begin == end)
		begin = 0;
	while (s[end - 1] == ' ' || s[end - 1] == '\n' || s[end - 1] == '\t')
		end--;
	trimmed = ft_strsub(s, (unsigned int)begin, (end - begin));
	if (!trimmed)
		return (NULL);
	return (trimmed);
}
