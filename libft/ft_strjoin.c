/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoignet <jcoignet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:03:12 by jcoignet          #+#    #+#             */
/*   Updated: 2015/05/28 19:35:29 by jcoignet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static char		*ft_join2(char *ret, char const *s2, int count)
{
	int		i;

	i = 0;
	if (!s2)
	{
		ret[count] = '\0';
		return (ret);
	}
	while (s2[i])
	{
		ret[count + i] = s2[i];
		i++;
	}
	ret[count + i] = '\0';
	return (ret);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	int		count;
	char	*ret;
	size_t	len;

	count = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	ret = (char*)malloc(sizeof(char) * len + 1);
	if (!ret)
		return (NULL);
	if (s1)
	{
		while (s1[count])
		{
			ret[count] = s1[count];
			count++;
		}
	}
	ret = ft_join2(ret, s2, count);
	return (ret);
}
