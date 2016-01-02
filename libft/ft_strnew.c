/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoignet <jcoignet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:57:24 by jcoignet          #+#    #+#             */
/*   Updated: 2015/05/28 19:36:10 by jcoignet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	count;

	count = 0;
	str = (char*)malloc(sizeof(char) * size + 1);
	if (str)
	{
		while (count < size)
		{
			str[count] = '\0';
			count++;
		}
		str[count] = '\0';
		return (str);
	}
	return (NULL);
}
