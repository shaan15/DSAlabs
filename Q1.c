#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int n,i=0;
	char str[100][100]; 
	printf("Enter the number of word: ");
	scanf("%d",&n);
	 for(i=0;i<n;i++){
	 	scanf("%s",str[i]);
	 }
	 str[n-1][strlen(str[n-1])-1]='\0';
	for(i=n-1;i>=0;i--){
		if(i==0){
			printf("%s.\n",str[i]);
		}
		else{
		printf("%s ",str[i]);
	}
}
return 0;
/*int n,i,j=0;
printf("enter size of string: ");
scanf("%d",&n);
char str[n];
gets(str);
for(i=n-1;i>=0;i--){
	if(str[i]==' '){

	}
}
}*/
}