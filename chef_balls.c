#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	printf("1\n");
	//fflush(stdout);
	printf("2 1 2\n");
	//fflush(stdout);
	printf("2 3 4\n");
	fflush(stdout);
	int diff;
	scanf("%d",&diff);
	if(diff == 0){
		printf("5\n");
		fflush(stdout);
	}
	else if(diff == 1){
		printf("1\n");
		//fflush(stdout);
		printf("1 1\n");
		//fflush(stdout);
		printf("1 2\n");
		fflush(stdout);
		scanf("%d",&diff);
		if(diff > 0){
			printf("1\n");
			fflush(stdout);
		}
		else{
			printf("2\n");
			fflush(stdout);
		}
		
	}
	else if(diff == -1){
		printf("1\n");
		//fflush(stdout);
		printf("1 3\n");
		//fflush(stdout);
		printf("1 4\n");
		fflush(stdout);
		scanf("%d",&diff);
		if(diff > 0){
			printf("3\n");
			fflush(stdout);
		}
		else{
			printf("4\n");
			fflush(stdout);
		}

	}
	return 0;
}