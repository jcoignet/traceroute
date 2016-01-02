/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoignet <jcoignet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 17:22:16 by jcoignet          #+#    #+#             */
/*   Updated: 2015/05/28 19:33:36 by jcoignet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		count;

	count = 0;
	if (src == dest)
		return (dest);
	if (src < dest && src + n > dest)
	{
		while (n > 0)
		{
			((char*)dest)[n - 1] = ((const char*)src)[n - 1];
			n--;
		}
	}
	else
	{
		while (count < n)
		{
			((char*)dest)[count] = ((const char*)src)[count];
			count++;
		}
	}
	return (dest);
}
