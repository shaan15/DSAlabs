#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int N;
		scanf("%d",&N);
		char str[N+1];
		scanf("%s",str);
		char *ptr;
		ptr=str+(N-1);
		for(;*ptr>=1;ptr--){
			printf("%c",*ptr);
		}
		printf("\n");
	}
}