#include <stdio.h>

int main(){
	int num, i, j;
	int sum = 0;
	printf("num : ");
	scanf("%d", &num);

	for(int i = num, j = 1; ; i--, j++){
		sum += (i+j);
	}
	

	return 0;
}
