/*#include<stdio.h>
#include<stdlib.h>

struct stack{
	int* stk;
	int top;
};
typedef struct stack STACK;
STACK s;

void stack_empty();
void push(int);
int pop();

void stack_empty(){
	if(s.top==-1){
		printf("stack is empty\n");
		return;
	}
	else{
		printf("stack is not empty\n");
		return;
	}

}

void push(int n){
	int num;
	if(s.top==(n-1)){
		printf("Stack is full\n");
		return;
	}
	else{
		printf("enter element to be pushed \n");
		scanf("%d",&num);
		s.top++;
		s.stk[s.top]=num;
	}
	return;
}

int pop(){
	int num;
	if(s.top==-1){
		printf("stack is empty\n");
		return(s.top);
	}
	else{
		num=s.stk[s.top];
		printf("popped element is %d\n",s.stk[s.top]);
		s.top--;
	}
	return num;
}

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

struct stack{
	int arr[MAX_SIZE];
	int top;
};
typedef struct stack STACK;

void pop(STACK *stk){
	if(stk->top==-1){
		printf("Stack underflow\n");
	}
	else{
		printf("Element popped: %d\n",stk->arr[stk->top]);
		stk->top-=1;
	}
}

void push(STACK *stk){
	if(stk->top==MAX_SIZE-1){
		printf("Stack Overflow\n");
	}
	else{
		int num;
		stk->top+=1;
		printf("Enter number to be pushed: ");
		scanf("%d",&num);
		stk->arr[stk->top]=num;
	}
}

int main(){
	STACK stk;
	stk.top=-1;
	int n;
	scanf("%d",&n);
	while(n--){
		char choice[5];
		scanf("%s",choice);
		if(strcmp(choice,"push")==0){
			push(&stk);
		}
		else if(strcmp(choice,"pop")==0){
			pop(&stk);
		}
	}
	return 0;
}