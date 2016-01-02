/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoignet <jcoignet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:21:38 by jcoignet          #+#    #+#             */
/*   Updated: 2015/05/28 19:35:21 by jcoignet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strdup(const char *s1)
{
	int		count;
	char	*cpy;

	count = 0;
	while (s1[count])
		count++;
	cpy = (char*)malloc(sizeof(char) * (count + 1));
	count = 0;
	if (cpy)
	{
		while (s1[count])
		{
			cpy[count] = s1[count];
			count++;
		}
	}
	else
		return (NULL);
	cpy[count] = '\0';
	return (cpy);
}
