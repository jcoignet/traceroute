/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_addline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoignet <jcoignet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/02 17:14:44 by jcoignet          #+#    #+#             */
/*   Updated: 2015/05/28 19:39:55 by jcoignet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		**ft_newtabline(char *line)
{
	char		**new;

	new = (char**)malloc(sizeof(char*) * 2);
	if (!new)
	{
		ft_putstr_fd("Error: malloc failed", 2);
		return (NULL);
	}
	new[0] = line;
	new[1] = NULL;
	return (new);
}

char			**tab_addline(char **tab, char *line)
{
	int		i;
	char	**new;

	i = 0;
	if (!line)
		return (tab);
	if (!tab)
		return (ft_newtabline(line));
	while (tab[i])
		i++;
	new = (char**)malloc(sizeof(char*) * (i + 2));
	if (!new)
	{
		ft_putstr_fd("Error: malloc failed", 2);
		return (NULL);
	}
	i = 0;
	while (tab[i])
	{
		new[i] = tab[i];
		i++;
	}
	new[i] = line;
	new[i + 1] = NULL;
	return (new);
}
