#include<stdio.h>
int main(void){
char *ptr;
char str[100];
scanf("%s",str);
ptr=str;
int count=0;

while(*ptr!='\0'){
count+=1;
*ptr++;}
printf("%d \n",count);
return 0;
}
