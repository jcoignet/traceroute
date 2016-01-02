/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoignet <jcoignet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:52:36 by jcoignet          #+#    #+#             */
/*   Updated: 2015/05/28 19:36:01 by jcoignet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t		count;

	count = 0;
	while (count < n)
	{
		if (s2[count])
			s1[count] = s2[count];
		else
			s1[count] = '\0';
		count++;
	}
	return (s1);
}
