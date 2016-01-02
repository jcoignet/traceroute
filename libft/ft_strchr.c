/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoignet <jcoignet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:11:26 by jcoignet          #+#    #+#             */
/*   Updated: 2015/05/28 19:35:07 by jcoignet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int		count;

	count = 0;
	while (s[count])
	{
		if (s[count] == (char)c)
			return ((char*)&s[count]);
		count++;
	}
	if (s[count] == (char)c)
		return ((char*)&s[count]);
	return (NULL);
}
