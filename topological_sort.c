#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 100

struct snode{
	int data;
	int dist;
	int final;
	char colour[6];
  struct snode * next;
	struct snode * p;
};
typedef struct snode node;
node *temp,*temp2,*temp3;
node * head[MAX_SIZE];
node * tail[MAX_SIZE];

struct stack{
	int arr[MAX_SIZE];
	int top;
};
typedef struct stack STACK;
STACK s;

void create(int value){
  	temp=(node *)malloc(sizeof(node));
  	temp->next=NULL;
  	temp->data=value;
	temp->p=NULL;
	temp->dist=0;
	temp->final=0;
	strcpy(temp->colour,"GRAY");
}

void insert_end(node ** head,node ** tail,int x){
  if(*head==NULL){
    create(x);
    *head=temp;
    *tail=temp;
  }
  else{
    create(x);
    temp->next=NULL;
    (*tail)->next=temp;
    (*tail)=temp;
  }
}



void pop(STACK *stk){
	if(stk->top==-1){
		return;
	}
	else{
		printf("%d ",stk->arr[stk->top]);
		stk->top--;
	}
}

void push(STACK *stk,int num){
	if(stk->top==MAX_SIZE-1){
		return;
	}
	else{
		stk->top++;
		stk->arr[stk->top]=num;
	}
}


void dfs_visit(node * u,int *t){
		(*t)=(*t)+1;
		u->dist=(*t);

		//push(&s,*t);
		strcpy(u->colour,"GRAY");
		node * temp4 = u->next;

		while(temp4 != NULL){
			temp2 = head[temp4->data];
			if(strcmp(temp2->colour,"WHITE")==0){
				temp2->p=u;
				dfs_visit(temp2,t);
			}
			temp4 =temp4->next;
		}
		strcpy(u->colour,"BLACK");
		(*t)=(*t)+1;
		u->final=(*t);
		push(&s,u->data);
}

void dfs(int n){
	int i;
	for(i=1 ; i<(n+1) ; i++){
		strcpy(head[i]->colour,"WHITE");
		head[i]->p=NULL;
	}
	int t=0;
	for(i=1 ; i<(n+1); i++){
		if(strcmp(head[i]->colour,"WHITE")==0){
			dfs_visit(head[i],&t);
		}
	}
}

void topological_sort(int n){
	dfs(n);
	while(s.top != -1){
		pop(&s);
	}
	printf("\n");

}

int main(){
	s.top = -1;
  	int i,n;
  	scanf("%d",&n);
	for(i=1;i<(n+1);i++){
		create(i);
		head[i]=temp;
		tail[i]=NULL;
	}

	int x,y;
 	scanf("%d %d",&x,&y);
  	while(x!=-1 && y!=-1){
    	insert_end(&(head[x]->next),&(tail[x]),y);
    	scanf("%d %d",&x,&y);
  }

	topological_sort(n);
	return 0;
}
