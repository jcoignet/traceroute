/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoignet <jcoignet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 13:42:03 by jcoignet          #+#    #+#             */
/*   Updated: 2015/05/28 19:33:27 by jcoignet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			count;
	int				ret;
	unsigned char	*temps1;
	unsigned char	*temps2;

	count = 0;
	temps1 = (unsigned char*)s1;
	temps2 = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (count < n)
	{
		if (temps1[count] != temps2[count])
		{
			ret = temps1[count] - temps2[count];
			return (ret);
		}
		count++;
	}
	return (0);
}
