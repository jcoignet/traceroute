/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traceroute.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoignet <jcoignet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/19 19:22:37 by jcoignet          #+#    #+#             */
/*   Updated: 2015/12/08 18:51:01 by jcoignet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TRACEROUTE_H
# define FT_TRACEROUTE_H

# include <stdlib.h>
# include <stdio.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <sys/socket.h>
# include <netdb.h>
# include <signal.h>
# include <netinet/ip_icmp.h>
# include <sys/time.h>
# include <errno.h>
# include "libft.h"

# define BUFSIZE IP_MAXPACKET
# define DEFAULT_TTL 30
# define DEFAULT_SEQ 3
# define DEFAULT_WAITTIME 5
# define ICMP_HEADER_LEN 8
# define DEFAULT_DATALEN 60
# define MIN_PACKET_SIZE 28
# define MAX_PACKET_SIZE 60000

typedef struct	s_starts
{
	double			tv_sec;
	double			tv_usec;
	int			seq;
	int			received;
	struct s_starts	*next;
}				t_starts;

typedef struct	s_ping
{
	int			sock;
	int			nb_sent;
	int			nb_recv;
	int			datalen;
	int			max_ttl;
	int			ttl;
	int			max_seq;
	int			errors;
	int			done;
	int			waittime;
	double			min_time;
	double			max_time;
	double			time_sum;
	double			time_sumsq;
	char			*hostname;
	char			*fqdn;
	char			*hostip;
	char			*progname;
	struct timeval	start_time;
	struct addrinfo	*info;
	t_starts		*starts;
}					t_ping;

double	ft_sqrt(double n);
t_ping	*mem_ping_data(t_ping *pdata);
void	pinger(t_ping *ping_data);
u_short	ft_checksum(u_short *data, int len);
void	ft_catch(t_ping *ping_data, int seq, int ite);
int		ft_options(int ac, char **av, t_ping *ping_data);
int		create_socket(t_ping *ping_data);

#endif
