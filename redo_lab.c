#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int N,i,j;
	printf("Input: ");
	scanf("%d",&N);
	char arr[N][N];
	char str[N];
	int num=N*N;
	printf("Enter N characters\n");
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			scanf(" %c",&arr[i][j]);
		}
	}


	printf("Enter input text: ");
	scanf("%s",str);
	int len=strlen(str);
	if(len!=N){
		return 1;
	}
	int k,flag=0,flag1;
	for(i=0;i<N;i++){
		flag=1;
		k=0;
		if(arr[i][0]==str[k]){
			for(j=1;j<N;j++){
				if(arr[i][j]!=str[++k]){
					flag=0;
					break;
				}
			}
		}
		else
			flag=0;
		if(flag==1){
			printf("Yes\n");
			return 0;
		
		}
	}

	for(j=0;j<N;j++){
		flag1=1;
		k=0;
		if(arr[0][j]==str[k])
		{
			for(i=1;i<N;i++)
			{
				if(arr[i][j]!=str[++k])
				{
					flag1=0;
					break;
				}
			}

		}
		else
			flag1=0;
		if(flag1==1){
				printf("Yes\n");
				return 0;
			}

	}
		printf("Nope \n");
		return 0;
}