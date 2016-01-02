/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoignet <jcoignet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 18:14:21 by jcoignet          #+#    #+#             */
/*   Updated: 2015/05/28 19:36:37 by jcoignet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_fill_strtrim(char *ret, const char *s, size_t start, size_t end)
{
	size_t	count;
	size_t	count2;

	count = 0;
	count2 = 0;
	while (s[count])
	{
		if (count <= end && count >= start)
		{
			ret[count2] = s[count];
			count2++;
		}
		count++;
	}
	ret[count2] = '\0';
	return (ret);
}

char		*ft_strtrim(char const *s)
{
	size_t		retlen;
	size_t		start;
	size_t		end;
	char		*ret;

	if (!s)
		return (NULL);
	start = 0;
	retlen = 0;
	retlen = ft_strlen(s);
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	end = retlen - 1;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	retlen = end + 1 - start;
	ret = (char*)malloc(sizeof(char) * retlen + 1);
	if (!ret)
		return (NULL);
	ret = ft_fill_strtrim(ret, s, start, end);
	return (ret);
}
