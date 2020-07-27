//Danica Medel
//2016-01028

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <signal.h>

#include <arpa/inet.h>

#define PORT "3490" // the port client will be connecting to 

#define MAXDATASIZE 100 // max number of bytes we can get at once 

void sigint_handler(int s)
{
    printf("\n");
    exit(1);
}

// get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa)
{
	if (sa->sa_family == AF_INET) {
		return &(((struct sockaddr_in*)sa)->sin_addr);
	}

	return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

int main(int argc, char *argv[])
{		
	struct sigaction sa;
	int sockfd, numbytes;  
	char buf[MAXDATASIZE];
	char buf2[MAXDATASIZE];
	struct addrinfo hints, *servinfo, *p;
	int rv;
	char s[INET6_ADDRSTRLEN];
	int new_fd, n; //new variables

	if (argc != 2) {
	    fprintf(stderr,"usage: client hostname\n");
	    exit(1);
	}

	sa.sa_handler = sigint_handler;
    sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	if ((rv = getaddrinfo(argv[1], PORT, &hints, &servinfo)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
		return 1;
	}

	// loop through all the results and connect to the first we can
	for(p = servinfo; p != NULL; p = p->ai_next) {
		if ((sockfd = socket(p->ai_family, p->ai_socktype,
				p->ai_protocol)) == -1) {
			perror("client: socket");
			continue;
		}

		if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
			perror("client: connect");
			close(sockfd);
			continue;
		}

		break;
	}

	if (p == NULL) {
		fprintf(stderr, "client: failed to connect\n");
		return 2;
	}

	inet_ntop(p->ai_family, get_in_addr((struct sockaddr *)p->ai_addr),
	s, sizeof s);
	printf("client: connecting to %s\n", s);

	freeaddrinfo(servinfo); // all done with this structure
//----------------------------------------------------------------------
	while(1)
	{
		if (sigaction(SIGINT, &sa, NULL) == -1) {
			perror("sigaction");
			exit(1);
		}    
		bzero(buf, 99);
		bzero(buf2, 99);
		char control[] = "exit";
		char control2[] = "refused";
		for(int a = 0; a < 5; a++)
		{
			buf2[a] = control[a];
		}
		printf("Input message(100 characters max): ");
		fgets(buf, 99, stdin);
		buf[strcspn(buf, "\n")] = 0;
		if(strcmp(buf, "exit") == 0)
		{
			printf("Client Closed.\n\n");
			exit(1);
		}
		else
		{
			write(sockfd, &buf, strlen(buf));
			if ((numbytes = recv(sockfd, buf2, MAXDATASIZE-1, 0)) == -1) 
			{
				perror("recv");
				exit(1);
			} 
			if(strlen(buf2) == 0 && strlen(buf) == 0)
			{
				printf("Server Disconnected; Client Closed.\n\n");
				exit(1);
			}
			buf[numbytes] = '\0';
			if(strcmp(buf2, "exit") == 0)
			{
				printf("Server Disconnected; Client Closed.\n\n");
				exit(1);
			}
			if(strcmp(buf2, control2) == 0)
			{
				printf("Connection Refused.\n\n");
				exit(1);
			}
			printf("server reply: %s\n\n",buf2);
		}
	}
	close(sockfd);
	return 0;
}

