#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void error(const char *msg){
	printf("%s", msg);
	exit(1);
}

int main(int argc, char *argv[]){

	printf("UDP Server by Jonah Mamakeesic\n");

	int sock_client;
	char buf[512];
	socklen_t addr_length = sizeof(struct sockaddr_in);
	struct sockaddr_in server, client;

	if (argc < 2) error("ERROR no port provided\n");

	sock_client = socket(AF_INET, SOCK_DGRAM, 0);
	if (sock_client < 0) error("ERROR opening socket");

	memset(&server, 0, addr_length);
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(atoi(argv[1]));

	if (bind(sock_client, (struct sockaddr*)&server, addr_length) < 0) 
		error("ERROR on binding");

	if (recvfrom(sock_client, buf, sizeof(buf), 0, (struct sockaddr*)&client, &addr_length) < 0) 
		error("ERROR on recvfrom");

	write(1, "Recieved a datagram: ", 21);
	write(1, buf, sizeof(buf));

	if (sendto(sock_client, "Message received.\n", 19, 0, (struct sockaddr*)&client, addr_length) < 0) 
		error("ERROR on sendto");
    
	close(sock_client);
	exit(0);
}