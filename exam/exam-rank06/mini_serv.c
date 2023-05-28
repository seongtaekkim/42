#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <sys/select.h>
#include <stdio.h>
#include <stdlib.h>

fd_set active, writefd, readfd;
int maxfd;
int clientId = 0;
char readbuf[1000000];
char writebuf[1000000];

typedef struct client {
	int id;
	char msg[1024];
} t_client;

int nextId() {
	clientId++;
	return clientId;
}

void fatal_error() {
    write(2, "Fatal error\n", 12);
    exit(1);
}

void broadcast(int s) {
    for (int i = 3; i <= maxfd; i++)
        if (FD_ISSET(i, &writefd) && i != s)
            send(i, writebuf, strlen(writebuf), 0);
	bzero(writebuf, strlen(writebuf));
}


int main(int ac, char* av[]) {
	if (ac != 2) {
		fatal_error();
	}
	int sockfd, connfd;
	struct sockaddr_in servaddr, cli; 
	t_client clients[FD_SETSIZE];
	socklen_t len;
	// socket create and verification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) { 
		printf("socket creation failed...\n"); 
		exit(0); 
	} 	
	else
		printf("Socket successfully created..\n"); 
	bzero(&servaddr, sizeof(servaddr)); 

	FD_ZERO(&active);
	bzero(clients, sizeof(clients));
	maxfd = sockfd;
	FD_SET(sockfd, &active);
	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(av[1])); 
  
	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) { 
		printf("socket bind failed...\n"); 
		exit(0); 
	} 
	else
		printf("Socket successfully binded..\n");
	if (listen(sockfd, 10) != 0) {
		printf("cannot listen\n"); 
		exit(0); 
	}
	// len = sizeof(cli);
	while (1) {
		readfd = writefd = active;
		if (select(maxfd + 1, &readfd, &writefd, NULL, NULL) < 0) {
			fatal_error();
		}
		for (int fd = 3 ; fd <= maxfd ; ++fd) {
			if (FD_ISSET(fd, &readfd)) {
				if (fd == sockfd) {
					connfd = accept(sockfd, (struct sockaddr *)&cli, &len);
					printf("connfd : %d\n",connfd);
					if (connfd < 0) { 
						fatal_error();
					}
					maxfd = connfd > maxfd ? connfd : maxfd;
					clients[connfd].id = nextId();
					FD_SET(connfd, &active);
					sprintf(writebuf, "server: client %d just arrived\n", clients[connfd].id);
					broadcast(connfd);
				} else {
					int nbyte = recv(fd, readbuf, 10000, 0);
					if (nbyte <= 0) {
						if (strlen(clients[fd].msg) > 0) {
							sprintf(writebuf, "client %d: %s", clients[fd].id, clients[fd].msg);
							broadcast(fd);
							bzero(clients[fd].msg, strlen(clients[fd].msg));
						}
						sprintf(writebuf, "server: client %d just left\n", clients[fd].id);
						broadcast(connfd);
						FD_CLR(fd, &active);
						close(fd);
					} else {
						int j = strlen(clients[fd].msg);
						for (int i = 0; i < nbyte ; ++i) {
							clients[fd].msg[j] = readbuf[i];
							if (readbuf[i] == '\n') {
								clients[fd].msg[j] = '\0';
								sprintf(writebuf, "client %d: %s\n", clients[fd].id, clients[fd].msg);
								broadcast(fd);
								j = -1;
								bzero(clients[fd].msg, strlen(clients[fd].msg));
							}
							j++;
						}
					}
					bzero(readbuf, strlen(readbuf));
				}
			}
		}
	}

}
