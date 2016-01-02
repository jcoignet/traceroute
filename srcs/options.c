/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoignet <jcoignet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:46:43 by jcoignet          #+#    #+#             */
/*   Updated: 2015/12/08 18:49:30 by jcoignet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

int	ft_usage(char *prog_name)
{
	dprintf(2, "Usage:\n%s [-h][-m max_ttl][-q nqueries][-w waittime] host [packlen]\n", prog_name);
	return (-1);
}

int		ft_nqueries(char *s, t_ping *ping_data)
{
	int	nqueries;

	if (s == NULL)
		return (ft_usage(ping_data->progname));
	nqueries = ft_atoi(s);
	if (nqueries > 10 || nqueries <= 0)
	{
		dprintf(2, "no more than 10 probes per hop (min 1)\n");
		return (-1);
	}
	ping_data->max_seq = nqueries;
	return (1);
}

int		ft_waittime(char *s, t_ping *ping_data)
{
	int	waittime;

	if (s == NULL)
		return (ft_usage(ping_data->progname));
	waittime = ft_atoi(s);
	if (waittime <= 0)
	{
		dprintf(2, "bad wait seconds `%s` specified\n", s);
		return (-1);
	}
	ping_data->waittime = waittime;
	return (1);
}

int		ft_ttl(char *s, t_ping *ping_data)
{
	int	ttl;

	if (s == NULL)
		return (ft_usage(ping_data->progname));
	ttl = ft_atoi(s);
	if (ttl > 255)
	{
		dprintf(2, "max hops cannot be more than 255\n");
		return (-1);
	}
	else if (ttl <= 0)
	{
		dprintf(2, "first hop out of range\n");
		return (-1);
	}
	ping_data->max_ttl = ttl;
	return (1);
}

int		packet_size(char *s, t_ping *ping_data)
{
	int	i = 0;
	int	size;

	while (s[i])
	{
	if (!ft_isdigit(s[i]))
	{
		dprintf(2, "cannot handle \"packetlen\" arg '%s'\n", s);
		return (-1);
	}
	i++;
	}
	size = ft_atoi(s);
	if (size < MIN_PACKET_SIZE)
		size = MIN_PACKET_SIZE;
	else if (size > MAX_PACKET_SIZE)
	{
		dprintf(2, "too big packlen %d specified\n", size);
		return (-1);
	}
	ping_data->datalen = size;
	return (0);
}

int		check_option(int index, char **av, t_ping *ping_data)
{
	char	c;

	c = av[index][1];
	if (c == 'h')
		return (ft_usage(av[0]));
	else if (c == 'm')
		return (ft_ttl(av[index + 1], ping_data));
	else if (c == 'q')
		return (ft_nqueries(av[index + 1], ping_data));
	else if (c == 'w')
		return (ft_waittime(av[index + 1], ping_data));
	ft_usage(av[0]);
	return (-1);
}

int	ft_options(int ac, char **av, t_ping *ping_data)
{
	int	i;
	int	target_count;
	int	ret;

	if (ac < 2)
		return (ft_usage(av[0]));
	i = 1;
	target_count = 0;
	while (i < ac)
	{
		if (av[i][0] == '-')
		{
			if ((ret = check_option(i, av, ping_data)) < 0)
				return (-1);
			else if (ret > 0)
				i += ret;
		}
		else if (target_count > 0 && ft_isdigit(av[i][0]))
		{
			if ((ret = packet_size(av[i], ping_data)) < 0)
				return (-1);
		}
		else
		{
			ping_data->hostname = ft_strdup(av[i]);
			target_count++;
		}
		i++;
	}
	if (target_count != 1)
		return (ft_usage(av[0]));
	return (0);
}
