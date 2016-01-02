/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoignet <jcoignet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 13:08:19 by jcoignet          #+#    #+#             */
/*   Updated: 2015/05/28 19:35:09 by jcoignet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strclr(char *s)
{
	int		count;

	count = 0;
	if (s)
	{
		while (s[count])
		{
			s[count] = '\0';
			count++;
		}
	}
}