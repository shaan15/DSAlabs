#include<stdio.h>

int main(void){
int n1,n2,sum,*p1,*p2;
scanf("%d %d",&n1,&n2);
p1=&n1;
p2=&n2;
sum=*p1+*p2;
printf("%d \n",sum);
return 0;
}
