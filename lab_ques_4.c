#include<stdio.h>
#include<stdlib.h>
int main(){
	int n;
	scanf("%d",&n);
	int **matrix=(int**)malloc(sizeof(int*)*n);
	for(i=0;i<n;i++){
		matrix[i]=(int*)malloc(n*sizeof(int));
}

int *p,a,b,i,j;
p=matrix1;

for(p=matrix1;p<&matrix1[n*n];p++){
	scanf("%d",matrix1);
}

for(a=0,i=n-1;a<n,i>=0;a++,i--){
	for(b=0,j=0;b<n,j<n;b++,j++){
		matrix[i][j]=matrix1[b][a];
	}
}
for(i=0;i<n;i++){
	for(j=0;j<n;j++){
		printf("%d",matrix[i][j]);
	}
	printf("\n");
}
return 0;
	}
