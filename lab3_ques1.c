#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int n,i=0;
	char str[100][100];
	
	
	printf("Enter no of words : ");
	scanf("%d",&n);
	

	for(i=0;i<n;i++){
		scanf("%s" , str[i]);
	}
	for (i = n-1; i >= 0; i--)
	{
		if(i==(n-1)){
			
		printf("%s ", str[i] );
	}

}