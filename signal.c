#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void timeout(int sig){
	if (sig==SIGALRM){
		puts("Time out!");
	}
	alarm(2);
}

void keycontrol(int sig){
	if(sig==SIGINT){
		puts("CTRL + C Pressed");
	}
}

int main(int argc, char* argv[]){

	return 0;
}
