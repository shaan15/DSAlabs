#include<stdio.h>
#include<stdlib.h>
#include<string.h>

 void sort(char *);

int main(){
	char str1[50],str2[50];
	printf("Enter string 1: ");
	scanf("%s",str1);
	printf("Enter string 2: ");
	scanf("%s",str2);
	int len;
	if(strlen(str1)!=strlen(str2)){
		printf("No!\n");

		return 0;
	}
	else{
		len=strlen(str1);
	}
	sort(str1);
	sort(str2);
	/*char *ptr1;
	char *ptr2;*/
	//int count=0;
	int i;
	for(i=0;i<len;i++){
		if(str1[i]!=str2[i]){
			printf("No!\n");
			return 0;
		}
		/*else{
			count++;
		}*/
	}
	//if(count==strlen(str1) && count==strlen(str2)){
	printf("Yes!\n");
	//}
	//else{
		//printf("No!\n");
	//}
	return 0;

}
 void sort(char *str){
 	int i=0,j=0,k;
 	char *ptr1,*ptr2;
 	for(i=0;i<strlen(str);i++){
 		for(j=i+1;j<strlen(str);j++){
 			ptr1=str+i;
 			ptr2=str+j;
 			if(*ptr1>*ptr2){
 				k=*ptr1;
 				*ptr1=*ptr2;
 				*ptr2=k;
 			}
 		}
 	}
 }