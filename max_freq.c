#include <stdio.h>
#include <stdlib.h>

int counting_sort(int* arr,int k,int size,int a,int b){
	int c[k+1],i;
	for(i=0;i<=k;i++){
			c[i]=0;
	}

	for(i=0;i<size;i++){
		c[arr[i]]++;
	}
	for(i=(a+1);i<=b;i++){
			c[i]+=c[i-1];
	}
	/*for(i=size-1;i>=0;i--){
		b[c[a[i]]-1]=a[i];
		c[a[i]]--;
	}*/
		if(a==0){
			return c[b];
		}
		else{
			return(c[b]-c[a-1]);
		}
	
}

int main(){
	int N;
	printf("Enter size of array: ");
	scanf("%d",&N);
	int arr[N],i;
	printf("Enter array elements: \n");
	for(i=0;i<N;i++){
		scanf("%d",&arr[i]);
	}
	//printf("\n");
	printf("Enter number of queries: ");
	int T;
	scanf("%d",&T);
	while(T--){
		int a,b;
		printf("Enter range of numbers: ");
		scanf("%d %d",&a,&b);
		printf("%d\n",counting_sort(arr,N,N,a,b));
	}
}
