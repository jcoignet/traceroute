/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoignet <jcoignet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:55:10 by jcoignet          #+#    #+#             */
/*   Updated: 2015/05/28 19:36:29 by jcoignet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	t_counters	ct;

	ct.count = 0;
	ct.count2 = 0;
	if (s2[ct.count] == '\0')
		return ((char*)s1);
	while (s1[ct.count])
	{
		while (s1[ct.count] == s2[ct.count2])
		{
			ct.count++;
			ct.count2++;
			if (s2[ct.count2] == '\0')
				return ((char*)&s1[ct.count - ct.count2]);
			else if (s1[ct.count] != s2[ct.count2] && s1[ct.count])
			{
				ct.count = ct.count + 1 - ct.count2;
				ct.count2 = 0;
			}
		}
		if (s1[ct.count] != s2[ct.count2] && s1[ct.count])
			ct.count++;
	}
	return (NULL);
}
