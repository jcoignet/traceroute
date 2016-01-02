/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pinger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoignet <jcoignet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 22:27:23 by jcoignet          #+#    #+#             */
/*   Updated: 2015/12/08 18:49:42 by jcoignet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

static void		add_start_time(struct timeval *start, t_ping *ping_data, int seq)
{
	t_starts	*new;
	t_starts	*tmp;

	if ((new = (t_starts*)ft_memalloc(sizeof(t_starts))) == NULL)
	{
		dprintf(2, "Malloc error.\n");
		exit(EXIT_FAILURE);
	}
	new->tv_sec = start->tv_sec;
	new->tv_usec = start->tv_usec;
	new->seq = seq;
	if (ping_data->starts == NULL)
	{
		ping_data->starts = new;
		return ;
	}
	tmp = ping_data->starts;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

static void		ft_ping(t_ping *ping_data, int seq, int ite)
{
	char	sendbuf[BUFSIZE];
	struct icmp	*icmp;
	int	sent;
	struct timeval	start;

	ping_data->nb_sent++;
	icmp = (struct icmp*)sendbuf;
	icmp->icmp_code = 0;
	icmp->icmp_type = ICMP_ECHO;
	icmp->icmp_cksum = 0;
	icmp->icmp_seq = seq;
	icmp->icmp_id = getpid();
	icmp->icmp_cksum = ft_checksum((u_short*)icmp, sizeof(struct icmp));
	gettimeofday(&start, NULL);
	add_start_time(&start, ping_data, ite);
	if ((sent = sendto(ping_data->sock, sendbuf, ping_data->datalen, 0,
					ping_data->info->ai_addr, ping_data->info->ai_addrlen)) < 0)
	{
		dprintf(2, "Error: sendto failed.\n");
		exit(EXIT_FAILURE);
	}
	if (sent != ping_data->datalen)
		dprintf(2, "Warning: sent %d expected %d\n", sent, ping_data->datalen);
	ft_catch(ping_data, seq, ite);
}

void		pinger(t_ping *ping_data)
{
	int	seq;

	seq = 1;
	int ite = 0;
	ping_data->ttl = 1;
	while (ping_data->ttl <= ping_data->max_ttl && !ping_data->done)// OR dst reached
	{
		if ((ping_data->sock = create_socket(ping_data)) < 0)
		{
			dprintf(2, "Sock error: %s\n", strerror(errno));
			exit(EXIT_FAILURE);
		}
		if (seq == 1)
			printf("%d ", ping_data->ttl);
		ft_ping(ping_data, seq, ite);
		seq = (seq >= ping_data->max_seq) ? 1 : seq + 1;
		if (seq == 1)
			ping_data->ttl++;
		close(ping_data->sock);
		ite++;
	}
}

