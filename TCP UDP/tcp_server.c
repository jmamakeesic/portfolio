#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg){
    printf("%s", msg);
    exit(1);
}

int main(int argc, char *argv[]){
    int sock_server, sock_client;
    char buf[512];
    struct sockaddr_in server_addr, client_addr;

    printf("TCP Server by Jonah Mamakeesic\n");

    if (argc < 2) {printf("usage %s port\n", argv[0]); exit(1);}

    sock_server = socket(PF_INET, SOCK_STREAM, 0);
    if (sock_server < 0) error("ERROR opening socket\n");

    // set address fields
    memset((char*)&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(sock_server, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) 
	error("ERROR on binding\n");

    if (listen(sock_server, 5) < 0) 
	error("ERROR on listening\n");

    int n = sizeof(client_addr);
    sock_client = accept(sock_server, (struct sockaddr*)&client_addr, (socklen_t*)&n);
    if (sock_client < 0) error("ERROR on accept\n");

    // clear buffer
    memset(buf, 0, sizeof(buf));

    if (read(sock_client, buf, sizeof(buf)-1) < 0) 
	error("ERROR reading from socket\n");

    printf("Received a segment: %s\n", buf);
    if (write(sock_client, "Message received.", 18) < 0) 
	error("ERROR writing to socket\n");
    
    close(sock_server);
    close(sock_client);

    exit(0); 
}
