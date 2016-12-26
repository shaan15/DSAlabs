#include<stdio.h>
int main(void)
{
 float income;
 printf("enter income: ");
 scanf("%f",&income);
 if (income < 200000.0)
 {
  printf ("tax rate is 0 \n");
 }
 else if ( income<400000.0 && income>=200000.0)
 {
  printf ("tax rate is 20 \n");
 }
 else if (income<600000.0 && income >= 400000.0)
 {
  printf ("tax rate is 30 \n");
 }
 else if (income>600000.0)
 {
  printf("tax is 35 \n");
 }
 return 0; 
}
