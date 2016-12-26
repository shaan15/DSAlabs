#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char fname[50];
	char linebuffer[1000][1000];
	int i=0,j=0;
	int charcount,linecount;
	printf("Enter the file name: ");
	scanf("%s",fname);	
	FILE *fptr;
	fptr=fopen(fname,"r");
	if(fptr==NULL){
		printf("Error!\n");
		exit(-1);
	}
	char ch=getc(fptr);
	for(j=0;ch!=EOF;j++){
		for(i=0;ch!='\n';i++){
			linebuffer[j][i]=ch;
		}
		linecount++;
	}
	char s2[5]=".txt";
	char s1[8]="shread_";
	char buffer[10];
	for(j=0;j<linecount;j++){
		//char j1=char(j+48);
		//itoa(j,buffer);
		//buffer=char(j+48);
		snprintf(buffer,sizeof(buffer),"%d",j);

		strcat(buffer,s2);
		strcat(s1,buffer);
		s1[14]='\0';

		FILE *fptrj;
		fptrj=fopen(s1,"w");
		fprintf(fptrj,"%s",linebuffer[j]);
		fclose(fptrj);
	}
	return 0;

	/*char ch = getchar(fptr);
	int count=0;
	while(ch!=EOF){
	while(ch!='\n'){
		line[count]=ch;
		count++;
		ch=getchar(fptr);

	}
	lineCount++;
}*/
}