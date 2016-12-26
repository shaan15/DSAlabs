#include<stdio.h>

int main(void)
{
 int test,num;
 int i=0;
 int count=0;
 int arr[100];
 printf("enter no. of inputs");
 scanf("%d",&test);
 while (count<test)
 {
  scanf("%d",&num);
  arr[i]=num;
  count++;
  i++; 
 }
 for(;i>=0;i++)
 {
  if(arr[i]>arr[i+1])
  {
   printf ("%d",arr[i]);
  }
  else
  {
   printf ("%d",arr[i+1]);
  }
 } 
 return 0;
}
