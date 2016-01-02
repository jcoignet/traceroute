/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoignet <jcoignet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 13:45:04 by jcoignet          #+#    #+#             */
/*   Updated: 2015/05/28 19:36:33 by jcoignet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	count;

	if (!s)
		return (NULL);
	count = 0;
	ret = (char*)malloc(sizeof(char) * len);
	if (ret)
	{
		while (s[count + start] && count < len)
		{
			ret[count] = s[count + start];
			count++;
		}
		ret[count] = '\0';
		return (ret);
	}
	return (NULL);
}
