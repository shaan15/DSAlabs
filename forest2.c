#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

struct trees{
	int ht[MAX_SIZE];
	int rate[MAX_SIZE];
};

typedef struct trees tree;
tree * root;
int total[MAX_SIZE];
int h[MAX_SIZE];
int ra[MAX_SIZE];

void merge(int *arr,int p,int q,int r){
	int i,j,k,s;
	int L[q-p+2],R[r-q+1];
	for(i=p,j=0;i<=q,j<=(q-p);i++,j++){
			L[j]=arr[i];
			//printf("copied to L\n");

	}
	for(s=q+1,k=0;s<=r,k<(r-q+1);s++,k++){
			R[k]=arr[s];
			//printf("copied to R\n");
	}
	L[q-p+1]=10000;
	R[r-q]=10000;
	//printf("sentinel declared\n");

	int m=0,n=0,x;
	for(x=p;x<=r;x++){
		if(L[m]<=R[n]){
			arr[x]=L[m];
			m++;
			//printf("L dominates\n");
		}
		else{
			arr[x]=R[n];
			n++;
			//printf("R dominates\n");
		}
	}
	//printf("merging done\n");

}

void merge_sort(int *arr,int start,int end){
	int mid;
	if(start<end){
	mid=(start+end)/2;
	//printf("mid found\n");


	merge_sort(arr,start,mid);
	merge_sort(arr,mid+1,end);
	merge(arr,start,mid,end);
	//printf("Now sorted!");
}
}

int main(){
	root = (tree*)malloc(sizeof(tree));
	int N,W,L;
	scanf("%d %d %d",&N,&W,&L);
	int i;
	for(i=0;i<N;i++){
		scanf("%d %d",&(root->ht[i]),&(root->rate[i]));
	}

	for(i=0;i<N;i++){
		total[i] = (L - (root->ht[i]))/(root->rate[i]);
	}
	merge_sort(total,0,N-1);

	for(i=0;i<N;i++){
		if(total[i]*(root->rate[i]) >= W){
			printf("%d\n",total[i]);
			return 0;
		}
		else{
			total[i]++;
			root->ht[i] += root->rate[i];
		}
	}
	return 0;
}