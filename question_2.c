#include<stdio.h>
int main(){
int arr[25];
int j=0;
for(j=0;j<25;j++){
scanf("%d",&arr[j]);
}
int i=1;
int *ptr;
int iMin=arr[0];
ptr=arr+i;
for(;*ptr<25;ptr++){
if(*ptr<iMin){
iMin=*ptr;
}
}
printf("%d \n",iMin);
return 0;
}
