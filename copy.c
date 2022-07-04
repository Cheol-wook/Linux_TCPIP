#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(){
	int sock;
	int pid;
	socket(AF_INET, SOCK_STREAM, 0);	//create socket

	
	pid = fork();	//processer copy
	
	if(pid == 0){
		printf("Child sock : %d \n", sock);
	}else{
		printf("Parent sock : %d \n", sock);
	}
	
	return 0;
}
