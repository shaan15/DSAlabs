#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
	int n,count;
	char *fname[40];
	char *line[100];
	printf("Enter file name: \n");
	scanf("%s",fname);
	file *fptr;
	fptr=fopen("fname","r");
	if(fptr==NULL){
		exit(-1);
	}
	else{
	fgets(line,strlen(line),fname);
		if(\n){

		}
	}
	return 0;
}