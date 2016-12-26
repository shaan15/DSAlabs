#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char str[100];
	printf("Enter the input string: ");
	scanf("%s",str);
	char *ptr,*ptr1;
	int count=0;
	for(ptr=str;*ptr!='\0';ptr++){
		for(ptr1=ptr+1;*ptr1!='\0';ptr1++){
			if(*ptr==*ptr1){
				printf("Not Unique\n");
				count++;
				exit(1);

			}
		}

	}
	if(count==0){
		printf("Unique\n");
	}
	return 0;

}