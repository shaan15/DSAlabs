#include<stdio.h>
void swap(int*,int*);

int main(){
int T,N,arr[N];
int i=0,j=0;
int *ptr;
scanf("%d \n",&T);
while(i<T){
scanf("%d \n",&N);
while(j<N){
scanf("%d",&arr[j]);
j++;
}
int k=0;
ptr=arr+k;
for(;*ptr<N;ptr=ptr+2){
swap(arr+i,arr+(i+1)); 
}
for(j=0;j<N;j++){
printf("%d",arr[j]);
}
i++;
}
return 0;
}


void swap(int *x,int *y){
int x_val=*x;
*x=*y;
*y=x_val;
}
