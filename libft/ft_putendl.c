/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoignet <jcoignet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:23:33 by jcoignet          #+#    #+#             */
/*   Updated: 2015/05/28 19:33:48 by jcoignet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	int		count;

	count = 0;
	if (!s)
		return ;
	while (s[count])
	{
		ft_putchar(s[count]);
		count++;
	}
	ft_putchar('\n');
}
