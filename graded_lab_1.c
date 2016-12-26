#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

//void pop();
//void push();
struct stack{
	char arr[MAX_SIZE];
	int top;
}stk;
//typedef struct stack STACK;

void pop(){
	if(stk.top==-1){
		return;
	}
	else{
		stk.top-=1;
	}
}

void push(char num){
/*	if(stk.top==MAX_SIZE-1){
		return;
	}*/
//	else{
		stk.top++;
		stk.arr[stk.top]=num;
//	}
}

int main(){
	int T;
	scanf("%d",&T);

	while(T--)
	{
	stk.top=-1;
		char str[10000];
		scanf("%s", stk.arr);
		int i;
//		printf("%s\n", stk.arr);
		int c=0;
		for(i=0; i<strlen(stk.arr); i++)
		{
			char f=stk.arr[i];
//			printf("%c ", f);
		if(f=='{' || f=='[' || f=='(')
			{push(f);
				//	printf("LOL\n");
			}
		else if(stk.top!=-1)
			{ if(stk.arr[stk.top]=='{' && f=='}')
				{
//				printf("ENTER\n");
				pop();
				c+=2;
			}
			else if(stk.top!=-1 && stk.arr[stk.top]=='(' && f==')')
			{
				pop();
				c+=2;
			}
			else if(stk.top!=-1 && stk.arr[stk.top]=='[' && f==']')
			{
				pop();
				c+=2;
			}
		}
			else stk.top=-1;
		}
		printf("%d\n", c);
	}
}