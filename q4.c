#include<stdio.h>
#define PRODUCT1 20
#define PRODUCT2 40
#define PRODUCT3 90
#define PRODUCT4 45
#define PRODUCT5 60
int main(void)
{
 int num,qty1,qty2,qty3,qty4,qty5,qty6,qty7,qty,total;
 printf("enter product no.: ");
 scanf("%d",&num);
 printf("enter quantity sold per day: ");
 scanf("%d %d %d %d %d %d %d",&qty1,&qty2,&qty3,&qty4,&qty5,&qty6,&qty7);
 qty=qty1+qty2+qty3+qty4+qty5+qty6+qty7;
 if(num==1)
 { 
  total=qty*PRODUCT1;
 }
 else if(num==2)
 {
  total=qty*PRODUCT2;
 }
 else if(num==3)
 {
  total=qty*PRODUCT3;
 }
 else if(num==4)
 { 
  total=qty*PRODUCT4;
 }
 else if(num==5)
 {
  total=qty*PRODUCT5;
 }
 else
 {
  printf("error");
 }
 printf("total is rupees %d \n",total);
}

