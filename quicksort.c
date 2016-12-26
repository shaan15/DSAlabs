#include<stdio.h>
#include<stdlib.h>

void quicksort(int*,int,int);
int partition(int*,int,int);
void swap(int*,int*);

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		int arr[n];
		int i;
		for(i=0;i<n;i++){
			scanf("%d",&arr[i]);
		}
		quicksort(arr,0,n-1);
		for(i=0;i<n;i++){
			printf("%d ",arr[i]);
		}
		printf("\n");
	}

}

void quicksort(int *arr,int p,int r){
	if(p<r){
		int q=partition(arr,p,r);
		quicksort(arr,p,q-1);
		quicksort(arr,q+1,r);
	}
}

int partition(int *arr,int p,int r){
	int x=arr[r];
	int i=p-1;
	int j;
	for(j=p;j<r;j++){
		if(arr[j]<=x){
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[r]);
	return(i+1);
}


void swap(int *x,int *y){
	int x_val=*x;
	*x=*y;
	*y=x_val;
}
