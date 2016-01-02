/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoignet <jcoignet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 15:49:07 by jcoignet          #+#    #+#             */
/*   Updated: 2015/05/28 19:35:34 by jcoignet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		count;
	size_t		dstlen;

	count = 0;
	dstlen = ft_strlen(dst);
	if (size <= dstlen)
		return (size + ft_strlen(src));
	while (count < size - dstlen - 1)
	{
		dst[count + dstlen] = src[count];
		if (dst[count + dstlen] == '\0')
			return (dstlen + ft_strlen(src));
		count++;
	}
	return (dstlen + ft_strlen(src));
}
