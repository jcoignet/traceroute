/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoignet <jcoignet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 22:31:03 by jcoignet          #+#    #+#             */
/*   Updated: 2015/12/08 18:50:05 by jcoignet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

static double		calculate_interval(t_ping *ping_data, int seq)
{
	struct timeval	end;
	t_starts		*start;
	double			interval;
	int			received;

	start = ping_data->starts;
	while (start->next != NULL && start->seq != seq)
		start = start->next;
	if (!start || start->seq != seq)
		return (0);
	received = 1;
	if (start->received == 1)
		received = -1;
	start->received = 1;
	gettimeofday(&end, NULL);
	interval = (double)((end.tv_sec - start->tv_sec) * 1000.0f);
	interval += (double)((end.tv_usec - start->tv_usec) / 1000.0f);
	ping_data->time_sum += interval;
	ping_data->time_sumsq += interval * interval;
	if (interval < ping_data->min_time)
		ping_data->min_time = interval;
	if (interval > ping_data->max_time)
		ping_data->max_time = interval;
	interval *= received;
	return (interval);
}

static void		treat_answer(t_ping *ping_data, int seq, int ite, struct ip *ip)
{
	double	itv;
	struct hostent	*client;
	char	ip_buf[BUFSIZE];

	itv = calculate_interval(ping_data, ite);
	if (seq == 1)
	{
		inet_ntop(AF_INET, (void*)&(ip->ip_src.s_addr), ip_buf, BUFSIZE);
		client = gethostbyaddr((void*)&(ip->ip_src.s_addr), sizeof(ip->ip_src.s_addr), AF_INET);
		if (client && client->h_name)
			printf("%s (%s)", client->h_name, ip_buf);
		else
			printf("%s (%s)", ip_buf, ip_buf);
	}
	if (itv > 0)
		printf("  %.2fms", itv);
}

static void		valid_msg(void *buf, t_ping *ping_data, int seq, int ite)
{
	struct ip	*ip;
	struct icmp	*icmp;
	int			ip_len;

	ip = (struct ip*)buf;
	ip_len = ip->ip_hl * 4;
	icmp = (struct icmp*)(buf + ip_len);

	if (icmp->icmp_type == ICMP_TIME_EXCEEDED)
	{
		treat_answer(ping_data, seq, ite, ip);
		ping_data->nb_recv++;
	}
	else
	{
		if (icmp->icmp_id != getpid())
		{
			ping_data->errors++;
			return ;
		}
		treat_answer(ping_data, seq, ite, ip);
		if (seq == ping_data->max_seq)
			ping_data->done = 1;
	}
	if (seq == ping_data->max_seq)
		printf("\n");
}

void		ft_catch(t_ping *ping_data, int seq, int ite)
{
	char			recvbuf[BUFSIZE];
	struct timeval	end;
	int				recv_len;

	if ((recv_len = recvfrom(ping_data->sock, (void*)recvbuf, sizeof(recvbuf), 0, NULL, 0)) < 0)
	{
		if (errno != EAGAIN)
		{
			ping_data->errors++;
			dprintf(2, "Error: recvmsg failed.\n");
		}
		else if (seq != ping_data->max_seq)
			printf(" *");
		else
			printf(" *\n");
		return ;
	}
	gettimeofday(&end, NULL);
	valid_msg((struct ip*)recvbuf, ping_data, seq, ite);
}
