#include <stdio.h>

#include <stdlib.h>

#include <string.h>


#define MAX_SIZE 100005


long long int ht[MAX_SIZE];

long long int rate[MAX_SIZE];


void adder(int N){

long long int i;

for(i=0;i<N;i++){

ht[i] = ht[i] + rate[i];

}

}


/*int min_returner(int N,int L,int W){

int min_ht = 0;

int j = 0;

int l;

for(l=0;l<N;l++){

if(ht[l] >= L){

min_ht = min_ht + ht[l];

}

if(min_ht >= W){

return 0;

}

}

//int val;


while(min_ht < W){

min_ht = 0;

j++;

adder(N);

int k;

for(k=0;k<N;k++){

if(ht[k] >= L){

min_ht = min_ht + ht[k];

}

if(min_ht >= W){

return j;

}

}

}

}*/


long long int min_returner(int N, int L, int W){

long long int start = 0;

long long int end = 1000000000000000000;

long long int mid = (start + end)/2;

// adder(N);

long long int i,wood;

wood=0;

for(i=0;i<N;i++)

  if(ht[i]>=L)

    wood+=ht[i];

 if(wood>=W)

    return 0;


while(start+1!=end){

wood=0;

for(i=0;i<N;i++)

  {

  

   if(ht[i]+mid*rate[i]>=L && wood<=W)

    wood+=ht[i]+ mid*rate[i];

  }







if(wood>W){
if(start==mid)
return mid;

end = mid;

mid = (start + end)/2;

}

else if(wood <W){
if(start==mid)
return end;

start = mid;

mid = (start + end)/2;

}

else{

return mid;

}

}

return mid+1;

}


int main(){

long long int N,W,L;

scanf("%lld %lld %lld",&N,&W,&L);

long long int i;

for(i=0;i<N;i++){

scanf("%lld %lld",&ht[i],&rate[i]);

}


printf("%lld\n",min_returner(N,L,W));

return 0;

}