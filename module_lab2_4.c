#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int N,i,j;
	printf("enter size of matrix: ");
	scanf("%d",&N);
	int arr[N][N];
	printf("Enter the elements:\n");
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			scanf(" %d",&arr[i][j]);
		}
	}
	printf("Output: \n");
	for(j=0;j<N;j++){
		for(i=(N-1);i>=0;i--){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}