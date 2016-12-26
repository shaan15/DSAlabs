#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

int top1=-1;
int top2=N;

void push1(int x,int arr[N]){
	if(top1<(top2-1)){
		top1++;
		arr[top1]=x;
		printf("Element pushed at index %d is %d\n",top1,x);
	}
	else{
		printf("Stack 1 overflow\n");
		return;
	}
}

void push2(int x,int arr[N]){
	if(top1<(top2-1)){
		top2--;
		arr[top2]=x;
		printf("Element pushed at index %d is %d\n",top2,x);
	}
	else{
		printf("Stack 2 overflow\n");
		return;
	}
}

void pop1(int arr[N]){
	if(top1>-1){
		int x=arr[top1];
		top1--;
		printf("Element popped from index %d is %d\n",(top1+1),x);
	}
	else{
		printf("Stack 1 underflow\n");
		return;
	}
}

void pop2(int arr[N]){
	if(top2<N){
		int x=arr[top2];
		top2++;
		printf("Element popped from index %d is %d\n",(top2-1),x);
	}
	else{
		printf("Stack 2 underflow\n");
		return;
	}
}

int main(){
	int arr[N];
	int Q;
	printf("Enter number of Queries: ");
	scanf("%d",&Q);
	while(Q--){
		char query[6];
		scanf("%s",query);
		if(strcmp(query,"push1")==0){
			int x;
			scanf("%d",&x);
			push1(x,arr);
		}

		else if(strcmp(query,"push2")==0){
			int y;
			scanf("%d",&y);
			push2(y,arr);
		}
		else if(strcmp(query,"pop1")==0){
			pop1(arr);
		}
		else if(strcmp(query,"pop2")==0){
			pop2(arr);
		}
	}
	return 0;

}
