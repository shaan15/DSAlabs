#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int min(int,int,int);

int main(){
	int N,i,j;
	printf("Input\n");
	scanf("%d",&N);
	int arr[N][N];
	int temp[N][N];
	//int n=N*N;
	//int a[n];
	printf("Input the elements\n");
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			scanf(" %d",&arr[i][j]);
		}
	}
	for(i=0;i<N;i++){
		if(arr[i][0]==0){
			temp[i][0]=1;
		}
		else{
			temp[i][0]=0;
		}

	}

	for(j=0;j<N;j++){
		if(arr[0][j]==0){
			temp[0][j]=1;
		}
		else{
			temp[0][j]=0;
		}
	}
	for(i=1;i<N;i++){
		for(j=1;j<N;j++){
			if(arr[i][j]==0){
				temp[i][j]=min(temp[i-1][j],temp[i][j-1],temp[i-1][j-1])+1;
			}
			else{
				temp[i][j]=0;
			}
		}
	}
	int a,b;
	int max=temp[0][0];
	for(a=0;a<N;a++){
		for(b=0;b<N;b++){
			if(temp[a][b]>max){
				max=temp[a][b];
			}

		}
	}
	printf("%d\n",max);
	return 0;


}

int min(int a,int b,int c){
	int mi=a;
	if(mi>b){
		mi=b;
	}
	if(mi>c){
		mi=c;
	}
	return mi;
}  