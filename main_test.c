#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;
	printf("전달된 인자 개수 : %d\n", argc);
	printf("실행 파일 : %s\n", argv[0]);
	for(i=1; i < argc; i++){
		printf("전달한 데이터 : %s\n", argv[i]);
	}
	
	
	return 0;
}
