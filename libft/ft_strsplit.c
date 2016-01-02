/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoignet <jcoignet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 18:53:03 by jcoignet          #+#    #+#             */
/*   Updated: 2015/05/28 19:36:25 by jcoignet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <string.h>

static size_t	ft_count_words(char const *s, char c)
{
	size_t		i;
	int			cpt;

	cpt = 0;
	i = 0;
	while (s[cpt])
	{
		if (s[cpt] != c && (s[cpt - 1] == c || cpt == 0))
			i++;
		cpt++;
	}
	return (i);
}

static size_t	ft_count_char(char const *s, char c, t_counters ct)
{
	while (s[ct.count] != c && s[ct.count])
	{
		ct.count++;
		ct.count2++;
	}
	return (ct.count2);
}

char			**ft_strsplit(char const *s, char c)
{
	t_counters	ct;
	char		**ret;

	if (!s)
		return (NULL);
	ct.count = 0;
	ct.index = 0;
	ret = (char**)malloc(sizeof(char*) * (ft_count_words(s, c) + 1));
	if (!ret)
		return (NULL);
	while (s[ct.count])
	{
		ct.count2 = 0;
		if (s[ct.count] != c && (s[ct.count - 1] == c || ct.count == 0))
		{
			ret[ct.index] = ft_strnew(ft_count_char(s, c, ct) + 1);
			ct.count2 = 0;
			while (s[ct.count] != c && s[ct.count])
				ret[ct.index][ct.count2++] = s[ct.count++];
			ct.index++;
		}
		ct.count++;
	}
	ret[ct.index] = NULL;
	return (ret);
}
