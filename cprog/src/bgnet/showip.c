#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>


#include "dbg.h"

int main(int argc, char **argv)
{
     check(argc == 2, "usage: showip www.example.com");

     struct addrinfo *res, *p, hints;
     int status;
     char ipstr[INET6_ADDRSTRLEN];
     
     memset(&hints, 0, sizeof hints);
     hints.ai_family = AF_UNSPEC;
     hints.ai_socktype = SOCK_STREAM;

     status = getaddrinfo(argv[1], NULL, &hints, &res);
     check(status == 0, "getaddrinfo: %s", gai_strerror(status));

     void *addr;
     char *ipver;
     
     for(p = res; p != NULL; p = p->ai_next) {
	  if(p->ai_family == AF_INET) {
	       struct sockaddr_in *ipv4 = (struct sockaddr_in *) p->ai_addr;
	       addr = &(ipv4->sin_addr);
	       ipver = "IPv4";
	  } else {
	       struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *) p->ai_addr;
	       addr = &(ipv6->sin6_addr);
	       ipver = "IPv6";
	  }

	  inet_ntop(p->ai_family, addr, ipstr, sizeof ipstr);
	  printf("  %s: %s\n", ipver, ipstr);
     }
     return 0;
error:
     return 1;
}
