#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int i=0,j=0,N1,N2,count=0;
	printf("Enter length of string 1: ");
	scanf("%d",&N1);
	printf("Enter length of string 2: ");
	scanf("%d",&N2);
	char str1[N1+1],str2[N2+1];
	for(i=0;i<N1;i++){
		scanf("%c",&str1[i]);
	}
	for(j=0;j<N2;j++){
		scanf("%c",&str2[j]);
	}
	if(N1!=N2){
		printf("Not equal!\n");
		return -1;
	}
	else{
	char *ptr1,*ptr2;
	//ptr1=str1;
	//ptr2=str1;
	for(ptr1=str1,ptr2=str2;*ptr1!='\0',*ptr2!='\0';ptr1++,ptr2++){
		/*if(*ptr1==*ptr2){
			count++;
		}

	}
	if(count==N1 && count==N2){
		printf("Equal Strings!\n");
	}
	else{
		printf("Not equal!\n");
	}*/
		if(*ptr1!=*ptr2){
			printf("Not equal!\n");
			return -1;
		}
		else{
			count++;
		}

	}
}
	/*if(count==N1 && count==N2){
		printf("Equal!\n");
	}*/
	
	return 0;
}
