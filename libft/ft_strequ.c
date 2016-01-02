/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoignet <jcoignet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 13:10:27 by jcoignet          #+#    #+#             */
/*   Updated: 2014/04/14 17:28:26 by jcoignet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strequ(char const *s1, char const *s2)
{
	int		count;

	count = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[count] && s2[count])
	{
		if (s1[count] == s2[count])
			count++;
		else
			return (0);
	}
	if (s1[count] == s2[count])
		return (1);
	return (0);
}
