#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void error(const char *msg){
	printf("%s", msg);
	exit(1);
}

int main(int argc, char *argv[]){

    	printf("UDP Client by Jonah Mamakeesic\n");

	int sock_server, length;
	char buf[512];
	struct sockaddr_in server, client;
	struct hostent *host;

	if (argc != 4) {printf("Usage: %s hostname port message\n", argv[0]); exit(1);}

	sock_server = socket(PF_INET, SOCK_DGRAM, 0);
	if (sock_server < 0) error("socket");

	server.sin_family = AF_INET;
	host = gethostbyname(argv[1]);

	if (host == 0) error("Unknown host");

	memcpy((char*)&server.sin_addr, (char*)host->h_addr, host->h_length);
	server.sin_port = htons(atoi(argv[2]));
	length = sizeof(struct sockaddr_in);

	memset(buf, 0, sizeof(buf));
	int n = strlen(argv[3]);
	memcpy(buf, argv[3], n);
	buf[n] = '\n';

	if (sendto(sock_server, buf, sizeof(buf), 0, (struct sockaddr*)&server, length) < 0) 
		error("sendto");

	if (recvfrom(sock_server, buf, sizeof(buf)-1, 0, (struct sockaddr*)&client, (socklen_t*)&length) < 0) 
		error("recvfrom");

	write(1, buf, sizeof(buf));
    
	close(sock_server);
	exit(0);
}























