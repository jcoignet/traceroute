/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoignet <jcoignet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 19:03:37 by jcoignet          #+#    #+#             */
/*   Updated: 2015/05/28 19:35:46 by jcoignet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		count;
	int		len;
	char	*ret;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	count = 0;
	ret = (char*)malloc(sizeof(char) * len + 1);
	if (!ret)
		return (NULL);
	while (s[count])
	{
		ret[count] = f(s[count]);
		count++;
	}
	ret[count] = '\0';
	return (ret);
}
