#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int,int*);

int main(){
	int T;
	printf("Enter number of test cases: ");
	scanf("%d",&T);
	while(T--){
		int N;
		int arr[N];
		printf("enter no.of elements of array: ");
		scanf("%d",&N);
		int i;
		for(i=0;i<N;i++){
			scanf("%d",&arr[i]);
		}
		insertion_sort(N,arr);
		for(i=0;i<N;i++){
			printf("%d ",arr[i]);
		}
		printf("\n");
	}
	return 0;
}

void insertion_sort(int n,int arr[]){
	int j,i,key;
	for(j=1;j<n;j++){
		key=arr[j];
		i=j-1;
		while(i>=0 && arr[i]>key){
			arr[i+1]=arr[i];
			i--;
		}
		arr[i+1]=key;
	}

}