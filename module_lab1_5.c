#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void sort(int,int *);

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int N,a;
		scanf("%d",&N);
		int arr[N];
		for(a=0;a<N;a++){
			scanf("%d",&arr[a]);
		}
		sort(N,arr);
		for(a=0;a<N;a++){
			printf("%d ",arr[a]);
		}
		printf("\n");

	}
	return 0;
}

void sort(int N,int *arr){
	int i=0,j=0,k;
	int *ptr1,*ptr2;
	for(i=0;i<N;i++){
		for(j=i+1;j<N;j++){
			ptr1=arr+i;
			ptr2=arr+j;
			if(*ptr1>*ptr2){
				k=*ptr1;
				*ptr1=*ptr2;
				*ptr2=k;
			}
		}
	}

}