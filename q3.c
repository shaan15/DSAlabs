#include<stdio.h>
#define A 5
#define D 5
#define L 500
#define ONE 1
int main(void)
{
 int sum,n,half;
 n=(L-A)/D + ONE;
 half=n/2;
 sum=half*(A+L);
 printf("%d \n",sum);
 return 0;
}
