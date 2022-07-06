#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <fcntl.h>
#define BUF_SIZE 2048
void error_handling(char *message);

char webpage[] = "HTTP/1.1 200 OK\r\n"
		"Server:Linux Web Server\r\n"
		"Content-Type: text/html; charset=UTF-8\r\n\r\n"
		"<!DOCTYPE html>\r\n"	
		"<html><head><title> My Web Page </title>\r\n"
		"<style>body {background-color: #FFFFFF }</style></head>\r\n"
		"<body><center><h1>Hello world!!</h1><br>\r\n"
      "<img src=\"earth.jpg\"></center></body></html>\r\n";

int main(int argc, char* argv[]){
	struct sockaddr_in serv_addr, clnt_addr;
	socklen_t sin_len = sizeof(clnt_addr);
	int serv_sock, clnt_sock;
	char buf[BUF_SIZE];
	int fdimg;
	int option = 1;
	char img_buf[700000];

	serv_sock=socket(AF_INET, SOCK_STREAM, 0);
	setsockopt(serv_sock, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(int));

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr=INADDR_ANY;
	serv_addr.sin_port=htons(atoi(argv[1]));

	if(bind(serv_sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr))==-1){
		error_handling("bind() error!");
	}
	if(listen(serv_sock, 5)==-1){
		error_handling("listen() error!");
	}

	while(1){
		clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &sin_len);
		puts("New client connected.....");
		read(clnt_sock, buf, BUF_SIZE);
		printf("%s\n", buf);

		if(!strncmp(buf, "GET /earth.jpg", 13)){
			fdimg = open("earth.jpg", O_RDONLY);
			read(fdimg, img_buf, sizeof(img_buf));
			write(clnt_sock, img_buf, sizeof(img_buf));
			close(fdimg);
		}
		else
		{
			write(clnt_sock, webpage, sizeof(webpage)-1);
			puts("closing......");
		}
		close(clnt_sock);
		}
	close(serv_sock);
	return 0;
}

void error_handling(char* message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
