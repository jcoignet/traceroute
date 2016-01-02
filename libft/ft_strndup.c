/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoignet <jcoignet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 20:07:23 by jcoignet          #+#    #+#             */
/*   Updated: 2015/06/05 18:44:14 by jcoignet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strndup(const char *s, int left, int right)
{
	int		count;
	char	*ret;

	ret = NULL;
	count = 0;
	ret = (char*)malloc(sizeof(char) * (right + 1 - left));
	if (!s || !ret)
		return (NULL);
	while (left < right)
	{
		if (s[left])
			ret[count] = s[left];
		else
			ret[count] = '\0';
		left++;
		count++;
	}
	ret[count] = '\0';
	return (ret);
}
