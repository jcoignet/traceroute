/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoignet <jcoignet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:49:00 by jcoignet          #+#    #+#             */
/*   Updated: 2015/10/15 22:30:18 by jcoignet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int		count;
	int		ret;

	count = 0;
	ret = 0;
	if (str[0] == '-' || str[0] == '+')
		count = 1;
	while (str[count] && str[count] >= 48 && str[count] <= 57)
	{
		ret = ret * 10 + str[count] - 48;
		count++;
	}
	if (str[0] == '-')
		ret = -ret;
	return (ret);
}
