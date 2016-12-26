#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	printf("1\n");
	//fflush(stdout);
	printf("2 1 2\n");
	//fflush(stdout);
	printf("3 3 4 5\n");
	fflush(stdout);
	int diff;
	scanf("%d",&diff);
	if(diff == 0){
		scanf("%d",&diff);
		if(diff == 1){
			printf("1\n");
			fflush(stdout);
		}
		else if(diff == -1){
			printf("2\n");
			fflush(stdout);
		}
	}
	else if(diff == -2){
		scanf("%d",&diff);
		if(diff == 0){
			printf("3\n");
			fflush(stdout);
		}
		else if(diff == -2){
			scanf("%d",&diff);
			if(diff == 1){
				printf("4\n");
				fflush(stdout);
			}
			else if(diff == -1){
				printf("5\n");
				fflush(stdout);
			}
		}
	}
	return 0;
}