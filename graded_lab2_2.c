#include<stdio.h>
#include<stdlib.h>
#include<string.h>

long int heap_extract_max(long int*,long int);
/*int heap_max(int*);*/
long int left(long int);
long int right(long int);
void swap(long int *,long int *);
void build_max_heap(long int*,long int);
void max_heapify(long int*,long int,long int);
long int heap_increase(long int*,long int,long int);
void max_heap_insert(long int*,long int,long int);
long int parent(long int);

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		long int N,M;
		scanf("%ld %ld",&N,&M);
		long int arr[N];
		long int i;
		for(i=0;i<N;i++){
			scanf("%ld",&arr[i]);
		}
		//printf("HI\n");
		build_max_heap(arr,N);
		//printf("2HI\n");
		// int max=heap_extract_max(arr,N);
		//printf("3HI\n");
		//printf("%d\n",max);
		long int count=0;
		while(M--){//
			//int temp=max;
			//printf("%d\n",arr[0]);
			//int saving=max/2;
			//temp=temp/2;
			// count+=(max-(max/2));
			// max=max/2;
			// max_heap_insert(arr,N,max);
			// //printf("4HI\n");
			// //arr[0]=arr[0]/2;
			// build_max_heap(arr,N);
			// ///printf("%d\n",arr[0]);
			// //printf("5HI\n");
			// //max_heapify(arr,0,N);
			// max=heap_extract_max(arr,N);

			//printf("6HI\n");
			//p//rintf("%d",max);
			count += arr[0] - arr[0]/2;
			arr[0] = arr[0]/2;
			max_heapify(arr, 0, N);

		}
		printf("%ld\n",count);

	}
	return 0;
}

void build_max_heap(long int *A,long int heapsize){
	long int i;
	for(i=(heapsize-1)/2;i>=0;i--){
		max_heapify(A,i,heapsize);
	}
}

/*int heap_max(int* A){
	return A[1];
}*/

long int heap_extract_max(long int *A,long int heapsize){
	if(heapsize<1){
		return 1;
	}
	long int max=A[0];
	A[0]=A[heapsize-1];
	heapsize--;
	max_heapify(A,0,heapsize);
	return max;
}

long int heap_increase(long int* A,long int i,long int key){
	if(key<A[i]){
		return 1;
	}
	A[i]=key;
	while(i>1 && A[parent(i)]<A[i]){
		swap(&A[i],&A[parent(i)]);
		i=parent(i);
	}

}

void max_heap_insert(long int* A,long int key,long int heapsize){
//heapsize--;
	A[heapsize]=-1;
	heap_increase(A,heapsize-1,key);

}

long int parent(long int i){
	return(i/2);
}

void max_heapify(long int* A,long int i,long int heapsize){
	long int l=left(i);
	long int r=right(i);
	long int largest;
	if(l<heapsize && A[l]>A[i]){
		largest=l;
	}
	else{
		largest=i;
	}
	if(r<heapsize && A[r]>A[largest]){
		largest=r;
	}
	if(largest!=i){
		swap(&A[i],&A[largest]);
		max_heapify(A,largest,heapsize);
	}
}

long int left(long int i){
	return(2*i);
}

long int right(long int i){
	return(2*i+1);
}

void swap(long int *x,long int *y){
	int x_val=*x;
	*x=*y;
	*y=x_val;
}
