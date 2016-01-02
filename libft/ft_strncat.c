/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoignet <jcoignet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:05:16 by jcoignet          #+#    #+#             */
/*   Updated: 2015/05/28 19:35:55 by jcoignet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		count;
	size_t		count2;

	count = 0;
	count2 = 0;
	while (s1[count])
		count++;
	while (count2 < n && s2[count2])
	{
		s1[count] = s2[count2];
		count++;
		count2++;
	}
	s1[count] = '\0';
	return (s1);
}
