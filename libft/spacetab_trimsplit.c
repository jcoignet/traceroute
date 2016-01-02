/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spacetab_trimsplit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoignet <jcoignet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 17:21:43 by jcoignet          #+#    #+#             */
/*   Updated: 2015/05/28 19:36:47 by jcoignet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		*ft_trim(const char *s)
{
	char	*ret;
	int		left;
	int		right;

	ret = NULL;
	left = 0;
	while (s[left] && (s[left] == ' ' || s[left] == '\t'))
		left++;
	if (!s[left])
		return (NULL);
	right = 0;
	while (s[right])
		right++;
	right--;
	while (right >= 0 && (s[right] == ' ' || s[right] == '\t'))
		right--;
	if (right <= left)
		return (NULL);
	ret = ft_strndup(s, left, right + 1);
	return (ret);
}

static int		count_words(const char *s)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\t')
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != ' ' && s[i] != '\t')
				i++;
		}
	}
	return (count);
}

static void		ft_split(const char *s, char ***ret)
{
	int		left;
	int		right;
	int		i;

	right = 0;
	i = 0;
	while (s[right])
	{
		if (s[right] == ' ' || s[right] == '\t')
			right++;
		else
		{
			left = right;
			while (s[right] && s[right] != ' ' && s[right] != '\t')
				right++;
			(*ret)[i] = ft_strndup(s, left, right);
			i++;
		}
	}
	(*ret)[i] = NULL;
}

static char		**spacetab_split(const char *s)
{
	int		words;
	char	**ret;

	words = count_words(s);
	ret = (char**)malloc(sizeof(char*) * (words + 1));
	if (!ret)
		return (NULL);
	ft_split(s, &ret);
	return (ret);
}

char			**spacetab_trimsplit(const char *s)
{
	char	*trimed;
	char	**ret;

	if (!s)
		return (NULL);
	if ((trimed = ft_trim(s)) == NULL)
		return (NULL);
	ret = spacetab_split(trimed);
	free(trimed);
	trimed = NULL;
	return (ret);
}
