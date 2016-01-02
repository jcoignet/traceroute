/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoignet <jcoignet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 17:14:54 by jcoignet          #+#    #+#             */
/*   Updated: 2015/05/28 19:33:17 by jcoignet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t		count;

	count = 0;
	while (count < n)
	{
		((unsigned char*)s1)[count] = ((unsigned char *)s2)[count];
		if (((unsigned char*)s1)[count] == (unsigned char)c)
		{
			count++;
			return (&((unsigned char*)s1)[count]);
		}
		count++;
	}
	return (NULL);
}
