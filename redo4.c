#include<stdio.h>
#include<stdlib.h>

int main(){
	char fname[20];
	char line[1000];
	int i,j,k;
	scanf("%s",fname);
	FILE *fptr;

	fptr=fopen(fname,"w");
	if(fptr==NULL){
		printf("Error!\n");
		exit(-1);
	}
	char ch=getc(fptr);
	for(i=0;ch!=EOF;i++){
		line[i]=ch;
		if(line[i]=='\' && line[i+1]=='*'){
			(line[i]=' ' && line[i+1]==' ');
			for(j=i+2;ch!=EOF;j++){
				if(line[j]=='*' && line[j+1]=='\'){
					(line[j]=' ' && line[j+1]=' ');
				}
			}
		}
		for(k=0;ch!='\n';k++){
			if(line[k]=='\' && line[k+1]=='\'){
				(line[k]==' ' && line[k+1]==' ');
			}
		}

	}
	fclose(fptr);
	return 0;

}
