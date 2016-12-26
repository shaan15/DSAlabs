#include<stdio.h>
int main(){
int i=0,j=0,k=0;
int T,N;
int *ptr;
char str[100];
scanf("%d",&T);
while(i<T){
scanf("%d",&N);
while(j<N){
scanf("%c",&str[j]);
j++;
}

i++;
}
return 0;
}

void reverse(){
char str[100], temp;
int i, j = 0;
printf("\nEnter the string :");
gets(str);
i = 0;
j = strlen(str) - 1; 
while (i < j) {
temp = str[i];
str[i] = str[j];
str[j] = temp;
i++;
j--;
}
printf("\nReverse string is :%s", str);
}
