/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoignet <jcoignet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/24 19:35:49 by jcoignet          #+#    #+#             */
/*   Updated: 2015/12/08 18:48:45 by jcoignet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

u_short		ft_checksum(u_short *data, int len)
{
	int				i;
	unsigned int	sum;
	u_short	checksum;
	ushort			*ptr;

	sum = 0;
	ptr = data;
	i = len;
	while (i > 1)
	{
		sum += *ptr;
		ptr += 1;
		i -= 2;
	}
	if (i == 1)
		sum += *((u_char*)ptr);
	sum = (sum & 0xFFFF) + (sum >> 16);
	sum += (sum >> 16);
	checksum = ~sum;
	return (checksum);
}

void		addr_info(t_ping *ping_data)
{
	struct addrinfo	*info;
	char			buf[BUFSIZE];
	struct hostent		*client;

	if (getaddrinfo(ping_data->hostname, NULL, NULL, &info) != 0)
	{
		dprintf(2, "%s: unknown host %s\n", ping_data->progname, ping_data->hostname);
		exit(EXIT_FAILURE);
	}
	inet_ntop(AF_INET,
			(void*)&(((struct sockaddr_in*)(info->ai_addr))->sin_addr.s_addr),
			buf, BUFSIZE);
	ping_data->hostip = ft_strdup(buf);
	ping_data->info = info;
	client = gethostbyaddr((void*)&(((struct sockaddr_in*)(info->ai_addr))->sin_addr.s_addr),
		sizeof(((struct sockaddr_in*)(info->ai_addr))->sin_addr.s_addr), AF_INET);
	if (client == NULL || client->h_name == NULL)
		ping_data->fqdn = ft_strdup(ping_data->hostname);
	else
		ping_data->fqdn = ft_strdup(client->h_name);
	printf("%s to %s (%s), %d hops max, %d byte packets\n",
		ping_data->progname, ping_data->hostname, ping_data->hostip, ping_data->max_ttl, ping_data->datalen);
	pinger(ping_data);
}

int	create_socket(t_ping *ping_data)
{
	int					sock;
	struct timeval to;

	if ((sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) == -1)
		return (-1);
	to.tv_sec = ping_data->waittime;
	to.tv_usec = 0;
	if (setsockopt(sock, IPPROTO_ICMP, SO_RCVTIMEO, (const void*)&to, sizeof(to)) < 0)
		return (-1);
	if (setsockopt(sock, IPPROTO_IP, IP_TTL, &(ping_data->ttl), sizeof(ping_data->ttl)) < 0)
		return (-1);
	return (sock);
}

int		main(int ac, char **av)
{
	t_ping	*ping_data;

	if ((ping_data = (t_ping*)ft_memalloc(sizeof(t_ping))) == NULL)
	{
		dprintf(2, "Malloc error.\n");
		return (EXIT_FAILURE);
	}
	ping_data->datalen = DEFAULT_DATALEN;
	ping_data->min_time = 100000.0f;
	ping_data->waittime = DEFAULT_WAITTIME;
	ping_data->max_ttl = DEFAULT_TTL;
	ping_data->max_seq = DEFAULT_SEQ;
	ping_data->progname = ft_strdup(av[0]);
	if (gettimeofday(&(ping_data->start_time), NULL) != 0)
	{
		dprintf(2, "Gettimeofday error.\n");
		exit(EXIT_FAILURE);
	}
	if (ft_options(ac, av, ping_data) < 0)
		return (EXIT_FAILURE);
	addr_info(ping_data);
	if (ping_data->errors > 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
