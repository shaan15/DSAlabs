#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int N,i,j;
	printf("Input\n");
	scanf("%d",&N);
	int arr[N][N];
	printf("Input the elements\n");
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			scanf(" %d",&arr[i][j]);
		}
	}
	int size=0;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(arr[i][j]==0){
				size=1;
				i=r;
				j=c;
				for(j=c;j<N;)
			}
		}
	}
}