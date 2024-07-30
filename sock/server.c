#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <asm-generic/socket.h>
#include <asm-generic/types.h>
#include <netinet/in.h>

#define PORT 5005

int main()
{
	struct sockaddr_in sad, cad;
	memset(&sad, 0, sizeof(sad));
	memset(&cad, 0, sizeof(cad));
	
	sad.sin_family = AF_INET;
	sad.sin_port = htons(PORT);
	sad.sin_addr.s_addr = htonl(INADDR_ANY);
	//printf("LE: %d		BE: %d\r\n", PORT, sad.sin_port);
	unsigned int fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	printf("socket open result : %d....\r\n", fd);
	
	int optvalue = 1;
	setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &optvalue, sizeof(optvalue));
	
	unsigned int saddrLen = sizeof(sad);
	int bnd = bind(fd, (struct sockaddr*)&sad, saddrLen);
	printf("binding result : %d....\r\n", bnd);
	listen(fd, 2); //waiting until request
	int addrLen = sizeof(cad);
	int client = accept(fd, (struct sockaddr*)&cad, &addrLen);
	printf("Accept client result : %d....\r\n", client);
	
	char buf[100];
	while(1)
	{
		int r = read(client, buf, 20);
		if(r == -1) break;
		write(client, "OK\r\n", 4);
		printf("Input : message > %s\r\n", buf);
		if(strcmp(buf, "exit") == 0) break;
	}
	close(client);
}
