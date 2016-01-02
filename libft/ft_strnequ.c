/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoignet <jcoignet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 13:23:37 by jcoignet          #+#    #+#             */
/*   Updated: 2015/05/28 19:36:06 by jcoignet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	count;

	if (!s1 || !s2)
		return (0);
	count = 0;
	while (s1[count] && s2[count] && count < n - 1)
	{
		if (s1[count] == s2[count])
			count++;
		else
			return (0);
	}
	if (s1[count] == s2[count])
		return (1);
	return (0);
}
