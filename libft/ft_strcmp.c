/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoignet <jcoignet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:00:07 by jcoignet          #+#    #+#             */
/*   Updated: 2014/04/14 17:28:19 by jcoignet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int		count;

	count = 0;
	while (s1[count] && s2[count] && s1[count] == s2[count])
		count++;
	return (s1[count] - s2[count]);
}
