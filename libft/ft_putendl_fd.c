/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoignet <jcoignet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:40:02 by jcoignet          #+#    #+#             */
/*   Updated: 2015/05/28 19:33:50 by jcoignet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	int		count;

	count = 0;
	while (s[count])
	{
		ft_putchar_fd(s[count], fd);
		count++;
	}
	ft_putchar_fd('\n', fd);
}
