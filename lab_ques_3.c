#include<stdio.h>

void compression(char *);

int main(){
	char str[1000];
	scanf("%s",str);
	compression(str);
	return 0;

}
void compression(char *str){
	int count=1;
	char *ptr;
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
}