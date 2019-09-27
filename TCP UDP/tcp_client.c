#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

void error(const char *msg){
    printf("%s", msg);
    exit(1);
}

int main(int argc, char *argv[]){
    int sock_client;
    char buf[512];
    struct sockaddr_in server_addr;
    struct hostent *host;

    printf("TCP Client by Jonah Mamakeesic\n");

    if (argc != 4) {printf("usage %s hostname port message\n", argv[0]); exit(1);}

    sock_client = socket(PF_INET, SOCK_STREAM, 0);
    if (sock_client < 0) error("ERROR opening socket\n");

    host = gethostbyname(argv[1]);
    if (host == NULL) {error("ERROR, no such host\n");}

    memset((char*)&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;

    memcpy((char*)&server_addr.sin_addr.s_addr, (char*)host->h_addr_list[0], host->h_length);
    server_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sock_client, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) 
        error("ERROR connecting\n");  

    if (write(sock_client, argv[3], strlen(argv[3])) < 0) 
        error("ERROR writing to socket\n");

    if (read(sock_client, buf, sizeof(buf)-1) < 0) 
        error("ERROR reading from socket\n");
    
    printf("%s\n", buf);

    close(sock_client);

    exit(0);
}
