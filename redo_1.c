#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
	int n,i;
	char str[100][100];
	printf("enter no. of words: ");
	scanf("%d",&n);

	for(i=0;i<n;i++){
		scanf("%s",str[i]);
	}
	str[n-1][strlen(str[n-1])-1]='\0';
	toupper(str[n-1][0]);
	tolower(str[0][0]);
	for(i=n-1;i>=0;i--){
		if(i==0){
			printf("%s.\n",str[i]);
		}
		else{
		printf("%s ",str[i]);
	}
}
	return 0;
}