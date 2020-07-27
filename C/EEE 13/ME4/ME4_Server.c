//Danica Medel
//2016-01028

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <ctype.h>

#define PORT "3490"  // the port users will be connecting to

#define BACKLOG 10     // how many pending connections queue will hold

#define MAXDATASIZE 100

int counter = 0;

void signal_handler(int signal)
{
    int saved_errno = errno;
    const char *signal_name;
    sigset_t pending;

    switch (signal) 
    {
        case SIGCHLD:
            while(waitpid(-1, NULL, WNOHANG) > 0);
            errno = saved_errno;
            counter--;
            break;
        case SIGINT:
            printf("\nSIGINT detected. Server Terminated.\n");
            exit(0);
        case SIGUSR1:
            counter--;
        default:
            fprintf(stderr, "Caught wrong signal: %d\n", signal);
            return;
    }   
}

// get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa)
{
    if (sa->sa_family == AF_INET) {
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }

    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

int main(void)
{
    int sockfd, new_fd;  // listen on sock_fd, new connection on new_fd
    struct addrinfo hints, *servinfo, *p;
    struct sockaddr_storage their_addr; // connector's address information
    socklen_t sin_size;
    struct sigaction sa;
    int yes=1;
    char s[INET6_ADDRSTRLEN];
    int rv;
    char buffer[256];
    char buffer1[256];
    int n;
    int a = 0;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE; // use my IP

    if ((rv = getaddrinfo(NULL, PORT, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    //socket create a communication endpoint (family, type, protocol)
    // loop through all the results and bind to the first we can
    for(p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype,
                p->ai_protocol)) == -1) {       
            perror("server: socket");
            continue;
        }

        if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes,
                sizeof(int)) == -1) {
            perror("setsockopt");
            exit(1);
        }

        //attach a local address to a socket (address of port, size of address)
        if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("server: bind");
            continue;
        }

        break;
    }

    freeaddrinfo(servinfo); // all done with this structure

    if (p == NULL)  {
        fprintf(stderr, "server: failed to bind\n");
        exit(1);
    }

    if (listen(sockfd, BACKLOG) == -1) {    //number of connections it can hold
        perror("listen");
        exit(1);
    }

    sa.sa_handler = &signal_handler; // reap all dead processes
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    if (sigaction(SIGCHLD, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }

    printf("server: waiting for connections...\n");

    while(1)   // main accept() loop  
    {  
        sin_size = sizeof their_addr;
        new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size); //gets a socket for an incoming client. socket id, client address, size of client address
        if (new_fd == -1) {
            perror("accept");
            continue;
        }

        inet_ntop(their_addr.ss_family,
            get_in_addr((struct sockaddr *)&their_addr),
            s, sizeof s);
        printf("server: got connection from %s\n", s);

        if (sigaction(SIGUSR1, &sa, NULL) == -1) {
            perror("sigaction");
            exit(1);
        }   

        if (!fork()) { // this is the child process
            if (sigaction(SIGINT, &sa, NULL) == -1) 
            {
                perror("sigaction");
                exit(1);
            }    
            close(sockfd); // child doesn't need the listener
            while(1)
            {
                int c = 0;
                bzero(buffer, 99);
                bzero(buffer1, 99);
                if (recv(new_fd, buffer, MAXDATASIZE, 0) == -1)
                perror("read");
                printf("received: %s\n", buffer);
                if(strlen(buffer) == 0 || strcmp(buffer, "exit") == 0)
                {
                    if(counter >= 1)
                    {
                        printf("Connection Terminated.\n\n");
                        exit(1);
                    }
                    printf("Connection Terminated.\n\n");
                    printf("Waiting for another client.\n");
                    exit(1);

                }
                else
                {
                    for(int a = 0; a != strlen(buffer); a++)
                    {
                        if(isalnum(buffer[a]) || buffer[a] == ' ')
                        {
                            buffer1[c++] = buffer[a];
                        }
                    }
                    printf("sent: %s\n", buffer1);
                    if (write(new_fd, &buffer1, 99) == -1)
                    perror("write");
                }
            }
            close(new_fd);
            exit(0);
        }
        
        counter++;
        if(counter > 1)
        {
            write(new_fd, "refused", sizeof("refused"));
        }

        close(new_fd);  // parent doesn't need this
    }

    return 0;
}
