#include<stdio.h>
#define N 10
void min_max(int a[],int n,int *min,int *max);
int main(void)
{
int b[N],i,big,small;
for (i=0;i<N;i++)
scanf("%d",&b[i]);
min_max(b,N,&big,&small);
printf("larges; %d \n", big);
printf("smallest %d",small);
return 0;
}
void min_max(int[a],int n,int *min, int *max)
{
int i;
*max=*min=a[0];
for(i=1;i<n;i++)
{
if(a[i]>*max)
*max=a[i];
e;se if(a[i]<*min)
*min=a[i]:
}
