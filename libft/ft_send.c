/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoignet <jcoignet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 18:22:08 by jcoignet          #+#    #+#             */
/*   Updated: 2015/11/04 18:30:05 by jcoignet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <stdio.h>

int		ft_send(int fd, char *msg, size_t len)
{
	ssize_t	se;

	se = send(fd, msg, len, 0);
	if (se <= 0)
	{
		printf("Error: couldn't send to fd %d.\n", fd);
		return (-1);
	}
	else if ((size_t)se != len)
	{
		printf("Warning: send %zd bytes, expected %zu to %d.\n", se, len, fd);
		return (-1);
	}
	return (1);
}
