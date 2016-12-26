#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	printf("1\n");
	fflush(stdout);
	printf("4 1 1 2 3\n");
	fflush(stdout);
	printf("4 3 4 5 5\n");
	fflush(stdout);
	int diff;
	scanf("%d",&diff);
	if(diff == 0){
		printf("2\n");
		printf("3\n");
		fflush(stdout);
	}
	else if(diff == 2){
		printf("2\n");
		printf("1\n");
		fflush(stdout);
	}
	else if(diff == -2){
		printf("2\n");
		printf("5\n");
		fflush(stdout);
	}
	else if(diff == 1){
		printf("2\n");
		printf("2\n");
		fflush(stdout);
	}
	else if(diff == -1){
		printf("2\n");
		printf("4\n");
		fflush(stdout);
	}

}