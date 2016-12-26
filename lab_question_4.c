#include<stdio.h>
#include<stdlib.h>
int main(){
	int n,i,j;
	scanf("%d",&n);
	int **matrix=(int**)malloc(sizeof(int*)*n);
	for(i=0;i<n;i++){
		matrix[i]=(int*)malloc(sizeof(int)*n);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&matrix[i][j]);

		}
	}
	for(j=0;j<n;j++){
		for(i=n-1;i>=0;i--){
			printf("%d",matrix[i][j]);
		}
		printf("\n");
	}
	return 0;

}