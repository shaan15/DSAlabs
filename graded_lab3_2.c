#include<stdio.h>
#include<stdlib.h>

int partition_diff(int*,int,int,int);
//int something(int*,int,int,int);
void swap(int*,int*);

int main(){
	int T,arr[10000],temp[10000];
	scanf("%d",&T);
	while(T--){
		int N,Q,L,R,k;
		scanf("%d %d",&N,&Q);
		//int arr[N];
		int i;
		for(i=0;i<N;i++){
			scanf("%d",&arr[i]);

		}
		while(Q--){
		//int m=0;
		int j;
		//int temp[10000];
		for(j=0;j<N;j++){
			temp[j]=arr[j];


		}
		//int L,R,k;
		scanf("%d %d %d",&L,&R,&k);
		k=k+L-1;
		//something(temp,L,R,k);
		printf("%d\n",partition_diff(temp,L,R,k));

	}
}
	return 0;
}

int partition_diff(int *arr,int p,int r,int k){
	int x=arr[r];
	if(p<r){
	int i=p-1;
	int j; 
	for(j=p;j<r;j++){
		if(arr[j]<=x){
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[r]);
	int pivot=i+1;
	if(k<pivot){
		return partition_diff(arr,p,pivot-1,k);
	}
	else if(k>pivot){
		return partition_diff(arr,pivot+1,r,k);
	}
	else{
		return arr[pivot];
	}
}
else{
	return arr[p];
}
}

/*int something(int *arr,int p,int r,int k){
	int pivot;
	if(p<r){

	pivot=partition(arr,p,r);
	if(k<pivot){
		return something(arr,p,pivot-1,k);
	}
	else if(k>pivot){
		return something(arr,pivot+1,r,k);
	}
	else{
		return arr[pivot];
	}
}
else{
	return arr[p];
}


}*/

void swap(int *x,int *y){
	int x_val=*x;
	*x=*y;
	*y=x_val;
}