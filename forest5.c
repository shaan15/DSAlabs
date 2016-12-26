#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000

struct trees{
	long long int ht[MAX_SIZE];
	long long int rate[MAX_SIZE];
	long long int total[MAX_SIZE];
};

typedef struct trees tree;
tree * root;


void merge(tree *arr,long long int p,long long int q,long long int r){
	long long int i,j,k,s;
	tree *L = (tree*)malloc(sizeof(tree));
	tree *R = (tree*)malloc(sizeof(tree));
	for(i=p,j=0;i<=q,j<=(q-p);i++,j++){
		
			L->ht[j]=arr->ht[i];
			L->rate[j]=arr->rate[i];
			L->total[j]=arr->total[i];
			//printf("copied to L\n");
		

	}
	for(s=q+1,k=0;s<=r,k<(r-q+1);s++,k++){
			R->ht[k]=arr->ht[s];
			R->rate[k]=arr->rate[s];
			R->total[k]=arr->total[s];
			//printf("copied to R\n");
	}
	// L[q-p+1]=100000;
	// R[r-q]=100000;
	//printf("sentinel declared\n");
	L->ht[q-p+1] = 100000;
	R->ht[r-q] = 100000;
	L->rate[q-p+1] = 100000;
	R->rate[r-q] = 100000;
	L->total[q-p+1] = 100000;
	R->total[r-q] = 100000;

	int m=0,n=0,x;
	for(x=p;x<=r;x++){
		if(L->total[m]<=R->total[n]){
			arr->ht[x]=L->ht[m];
			arr->rate[x]=L->rate[m];
			arr->total[x]=L->total[m];
			m++;
			//printf("L dominates\n");
		}
		else{
			arr->ht[x]=R->ht[n];
			arr->rate[x]=R->rate[n];
			arr->total[x]=R->total[n];
			n++;
			//printf("R dominates\n");
		}
	}
	 //printf("merging done\n");
	 // for(i=0;i<r;i++)
		// printf("%lld %lld %lld\n",arr->ht[i],arr->rate[i],arr->total[i]);

}

void merge_sort(tree *arr,long long int start,long long int end){
	int mid;
	if(start<end){
	mid=(start+end)/2;
	//printf("mid found\n");


	merge_sort(arr,start,mid);
	//printf("first");
	merge_sort(arr,mid+1,end);
	//printf("second");
	merge(arr,start,mid,end);
	//printf("Now sorted!");
}
}

int main(){
	//totel = (tree*)malloc(sizeof(tree));
	root = (tree*)malloc(sizeof(tree));
	long long int N,W,L;
	scanf("%lld %lld %lld",&N,&W,&L);
	long long int i,j;
	for(i=0;i<N;i++){
		scanf("%lld %lld",&(root->ht[i]),&(root->rate[i]));
	}

	for(i=0;i<N;i++){
		if((L - (root->ht[i]))%(root->rate[i])==0)
			root->total[i] = (L - (root->ht[i]))/(root->rate[i]);
		else
			root->total[i] = (L - (root->ht[i]))/(root->rate[i])+1;
	}
	merge_sort(root,0,N-1);
	/*for(i=0;i<N;i++)
		printf("%lld %lld %lld\n",root->ht[i],root->rate[i],root->total[i]);*/
	long long int min_ht = root->total[0];
	long long int H = 0;
	//H = 0;
	long long int R = 0;
	//R = 0;
	for(i=0;i<N;i++){
		if(root->ht[i] > L){
			H += root->ht[i];
			R += root->rate[i];
		}
		if(root->ht[i] + min_ht*(root->rate[i]) >= W){
			printf("%lld\n",min_ht);
			return 0;
		}
		else if((L - (root->ht[i]))/root->rate[i] > (W - (root->ht[i]))/root->rate[i]){
			min_ht =+ (W - (root->ht[i]))/root->rate[i];

		}
		else if((L - (root->ht[i]))/root->rate[i] < (W - (root->ht[i]))/root->rate[i]){
			min_ht += (L - (root->ht[i]))/root->rate[i];
		}
		
		
		}
		printf("%lld\n",min_ht);
		/*for(j=0;j<N;j++)		printf("%lld %lld %lld\n",root->ht[j],root->rate[j],root->total[j]);*/
		return 0;
	}