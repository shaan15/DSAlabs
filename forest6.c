#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

int ht[MAX_SIZE];
int rate[MAX_SIZE];

void adder(int N){
	int i;
	for(i=0;i<N;i++){
		ht[i] = ht[i] + rate[i];
	}
}

int min_returner(int N,int L,int W){
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
}

int main(){
	int N,W,L;
	scanf("%d %d %d",&N,&W,&L);
	int i;
	for(i=0;i<N;i++){
		scanf("%d %d",&ht[i],&rate[i]);
	}

	printf("%d\n",min_returner(N,L,W));
	return 0;
}