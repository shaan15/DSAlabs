#include<stdio.h>
#include<stdlib.h>
void swap(int*,int*);
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int N;
		scanf("%d",&N);
		int arr[N],i;
		for(i=0;i<N;i++){
			scanf("%d",&arr[i]);
		}
		if(N%2!=0){
			printf("Your array has odd number of elements!\n");
			
		}
		else{
		int *ptr;
		ptr=arr;
		for(ptr=arr;*ptr<N;ptr+=2){
			swap(ptr,(ptr+1));
		}

		for(i=0;i<N;i++){
			printf("%d ",arr[i]);
		}
		printf("\n");
	}

}
return 0;
}

void swap(int *x,int *y){
	int val=*x;
	*x=*y;
	*y=val;
}