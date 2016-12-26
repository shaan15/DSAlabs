#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int N,i=0;
		scanf("%d",&N);
		char str[N+1];
		char str1[N+1];
		char *ptr;
		char *ptr1;
		//ptr1=str+i;
		for(i=0;i<N+1;i++){
			scanf("%c",(str+i));
		}
		//(str+N)='\0';
		ptr=str+N;
		ptr1=str1;
		int j=N;
		//ptr=s+N;
		//for(i=N,i>=0;i--)

		for(;j>=0;j--){
			*ptr1=*ptr;
			ptr--;
			ptr1++;

		}
		for(i=0;i<N;i++)
			printf("%c",str1[i]);
		printf("\n");
	}
		return 0;
}