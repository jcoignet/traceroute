/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoignet <jcoignet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:07:49 by jcoignet          #+#    #+#             */
/*   Updated: 2015/05/28 19:33:05 by jcoignet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*fill_ret(int n, t_itoa_var s)
{
	s.ret = (char*)malloc(sizeof(char) * (s.size + 1));
	s.index = 0;
	if (n < 0)
	{
		s.ret[0] = '-';
		s.index++;
		n = -n;
		s.size--;
	}
	while (s.size > 0)
	{
		s.count = 0;
		s.val = n;
		while (s.count < s.size - 1)
		{
			s.val = s.val / 10;
			s.count++;
		}
		s.val = s.val % 10;
		s.ret[s.index] = 48 + s.val;
		s.index++;
		s.size--;
	}
	s.ret[s.index] = '\0';
	return (s.ret);
}

char		*ft_itoa(int n)
{
	t_itoa_var	s;

	s.size = 1;
	s.val = n;
	if (n < 0)
	{
		s.size++;
		if (n < -2147483647)
			return (ft_strdup("-2147483648"));
	}
	while (s.val > 10 || s.val < -10)
	{
		s.val = s.val / 10;
		s.size++;
	}
	s.ret = (char*)malloc(sizeof(char) * (s.size + 1));
	if (!s.ret)
		return (NULL);
	s.ret = fill_ret(n, s);
	return (s.ret);
}
