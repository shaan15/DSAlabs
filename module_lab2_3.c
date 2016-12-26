#include<stdio.h>
#include<stdlib.h>
 int main(){
 	char str[100];
 	printf("Enter the input string: ");
 	scanf("%s",str);
 	char *ptr;
 	ptr=str;
 	int count=1;
 	for(ptr=str;*ptr!='\0';ptr++){
 		if(*ptr==*(ptr+1)){
 			count++;
 		}
 		else{
 			printf("%c%d",*ptr,count);
 			count=1;
 		}
 	}
 	printf("\n");
 	return 0;
 }